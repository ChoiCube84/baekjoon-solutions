#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph(100001);
bool visited[100001] = { 0, };

int furthestNode = 0;
int furthestLength = -1;

void dfs(int node, int distance);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, nodeA, nodeB, weight;

	cin >> V;

	for (int i = 0; i < V; i++) {
		cin >> nodeA;

		while (true) {
			cin >> nodeB;
			if (nodeB == -1) {
				break;
			}
			else {
				cin >> weight;
				pair<int, int> tempNode = { nodeB, weight };
				graph[nodeA].emplace_back(tempNode);
			}
		}
	}

	dfs(1, 0);

	for (int i = 1; i <= V; i++) {
		visited[i] = false;
	}

	int startNode = furthestNode;
	furthestNode = 0;
	furthestLength = -1;

	dfs(startNode, 0);

	cout << furthestLength;

	return 0;
}

void dfs(int node, int distance) {
	if (!visited[node]) {
		visited[node] = true;
		
		if (distance > furthestLength) {
			furthestLength = distance;
			furthestNode = node;
		}

		for (auto nextNode : graph[node]) {
			dfs(nextNode.first, distance + nextNode.second);
		}
	}
}
