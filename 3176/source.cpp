#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> tree(100001);

int depth[100001] = { 0, };
int parent[100001][18] = { 0, };
int minimumPath[100001][18] = { 0, };
int maximumPath[100001][18] = { 0, };
bool visited[100001] = { 0, };

void setImmediateParent(int currentNode, int currentDepth);
void setParentDP(int N);
int findLCA(int nodeA, int nodeB);

void findShortestAndLongestRoads(int nodeA, int nodeB, int& minimum, int& maximum);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K, nodeA, nodeB, length;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> nodeA >> nodeB >> length;

		tree[nodeA].emplace_back(make_pair(nodeB, length));
		tree[nodeB].emplace_back(make_pair(nodeA, length));
	}

	setImmediateParent(1, 0);
	setParentDP(N);

	cin >> K;

	for (int i = 0; i < K; i++) {
		int minimum = INT_MAX;
		int maximum = 0;

		cin >> nodeA >> nodeB;
		
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}

		findShortestAndLongestRoads(nodeA, nodeB, minimum, maximum);
		cout << minimum << " " << maximum << "\n";
	}

	return 0;
}

void setImmediateParent(int currentNode, int currentDepth) {
	visited[currentNode] = true;
	depth[currentNode] = currentDepth;

	for (auto i : tree[currentNode]) {
		if (visited[i.first] == false) {
			parent[i.first][0] = currentNode;

			minimumPath[i.first][0] = i.second;
			maximumPath[i.first][0] = i.second;

			setImmediateParent(i.first, currentDepth + 1);
		}
	}
}

void setParentDP(int N) {
	int maximumHeight = 0;

	for (int tempN = N; tempN > 1; maximumHeight++) {
		tempN >>= 1;
	}

	for (int i = 1; i <= maximumHeight; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			
			minimumPath[j][i] = min(minimumPath[j][i - 1], minimumPath[parent[j][i - 1]][i - 1]);
			maximumPath[j][i] = max(maximumPath[j][i - 1], maximumPath[parent[j][i - 1]][i - 1]);
		}
	}
}

int findLCA(int nodeA, int nodeB) {
	if (depth[nodeA] < depth[nodeB]) {
		swap(nodeA, nodeB);
	}

	int difference = depth[nodeA] - depth[nodeB];
	int power = 0;

	while (difference > 0) {
		if (difference % 2 == 1) {
			nodeA = parent[nodeA][power];
		}
		difference = difference >> 1;
		power++;
	}

	if (nodeA == nodeB) {
		return nodeA;
	}
	else {
		for (int i = 17; i >= 0; i--) {
			if (parent[nodeA][i] != 0 && parent[nodeA][i] != parent[nodeB][i]) {
				nodeA = parent[nodeA][i];
				nodeB = parent[nodeB][i];
			}
		}

		return parent[nodeA][0];
	}
}

void findShortestAndLongestRoads(int nodeA, int nodeB, int& minimum, int& maximum) {
	int difference, power;
	int LCA = findLCA(nodeA, nodeB);

	difference = depth[nodeA] - depth[LCA];
	power = 0;

	while (difference > 0) {
		if (difference % 2 == 1) {
			minimum = min(minimum, minimumPath[nodeA][power]);
			maximum = max(maximum, maximumPath[nodeA][power]);

			nodeA = parent[nodeA][power];
		}
		difference >>= 1;
		power++;
	}

	difference = depth[nodeB] - depth[LCA];
	power = 0;

	while (difference > 0) {
		if (difference % 2 == 1) {
			minimum = min(minimum, minimumPath[nodeB][power]);
			maximum = max(maximum, maximumPath[nodeB][power]);

			nodeB = parent[nodeB][power];
		}
		difference >>= 1;
		power++;
	}
}
