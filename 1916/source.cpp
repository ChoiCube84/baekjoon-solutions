#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int N, M;
vector<int> shortest;
vector<pii> graph[1001];

struct cmp {
	bool operator()(const pii& p1, const pii& p2) {
		return p1.second > p2.second;
	}
};

void dijkstra(int departure);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	shortest.resize(N + 1, INT_MAX);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start].emplace_back(make_pair(end, cost));
	}

	int departure, destination;
	cin >> departure >> destination;

	dijkstra(departure);

	cout << shortest[destination];

	return 0;
}

void dijkstra(int departure) {
	priority_queue<pii, vector<pii>, cmp> pq;

	shortest[departure] = 0;
	pq.push(make_pair(departure, 0));

	while (!pq.empty()) {
		pii currentNode = pq.top();
		pq.pop();

		if (currentNode.second > shortest[currentNode.first]) continue;

		for (auto& nextNode : graph[currentNode.first]) {
			if (shortest[nextNode.first] > shortest[currentNode.first] + nextNode.second) {
				shortest[nextNode.first] = currentNode.second + nextNode.second;
				pq.push(make_pair(nextNode.first, shortest[nextNode.first]));
			}
		}
	}
}
