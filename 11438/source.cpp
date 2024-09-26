#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree(100001);

int depth[100001] = { 0, };
int parent[100001][18] = { 0, };
bool visited[100001] = { 0, };

void setImmediateParent(int currentNode, int currentDepth);
void setParentDP(int N);
int findLCA(int nodeA, int nodeB);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, nodeA, nodeB;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> nodeA >> nodeB;

		tree[nodeA].emplace_back(nodeB);
		tree[nodeB].emplace_back(nodeA);
	}

	setImmediateParent(1, 0);
	setParentDP(N);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> nodeA >> nodeB;
		cout << findLCA(nodeA, nodeB) << "\n";
	}

	return 0;
}

void setImmediateParent(int currentNode, int currentDepth) {
	visited[currentNode] = true;
	depth[currentNode] = currentDepth;

	for (auto i : tree[currentNode]) {
		if (visited[i] == false) {
			parent[i][0] = currentNode;
			setImmediateParent(i, currentDepth + 1);
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
