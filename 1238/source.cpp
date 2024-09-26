#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

int numberOfStudents;

int shortestDistanceToParty[1001] = { 0, };
int shortestDistanceToBye[1001] = { 0, };

vector<pair<int, int>> graphToParty[1001];
vector<pair<int, int>> graphToBye[1001];

void dijkstra(int departure, bool goToParty);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int numberOfRoads, destination;
	cin >> numberOfStudents >> numberOfRoads >> destination;

	for (int i = 1; i <= numberOfStudents; i++) {
		if (i != destination) {
			shortestDistanceToParty[i] = INT_MAX;
			shortestDistanceToBye[i] = INT_MAX;
		}
	}

	for (int i = 0; i < numberOfRoads; i++) {
		int nodeA, nodeB, tempTime;
		cin >> nodeA >> nodeB >> tempTime;

		graphToParty[nodeB].emplace_back(make_pair(nodeA, tempTime));
		graphToBye[nodeA].emplace_back(make_pair(nodeB, tempTime));
	}

	dijkstra(destination, true);
	dijkstra(destination, false);

	priority_queue<int> pq;
	for (int i = 1; i <= numberOfStudents; i++) {
		pq.push(shortestDistanceToParty[i] + shortestDistanceToBye[i]);
	}

	cout << pq.top();

	return 0;
}

void dijkstra(int departure, bool goToParty) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	bool checked[1001] = { 0, };

	pq.push(make_pair(departure, 0));

	while (!pq.empty()) {
		pair<int, int> currentNode = pq.top();
		pq.pop();

		if (checked[currentNode.first] == true) {
			continue;
		}

		checked[currentNode.first] = true;

		if (goToParty) {
			for (auto i : graphToParty[currentNode.first]) {
				if (shortestDistanceToParty[i.first] > currentNode.second + i.second) {
					shortestDistanceToParty[i.first] = currentNode.second + i.second;
					pq.push(make_pair(i.first, shortestDistanceToParty[i.first]));
				}
			}
		}
		else {
			for (auto i : graphToBye[currentNode.first]) {
				if (shortestDistanceToBye[i.first] > currentNode.second + i.second) {
					shortestDistanceToBye[i.first] = currentNode.second + i.second;
					pq.push(make_pair(i.first, shortestDistanceToBye[i.first]));
				}
			}
		}
	}
}
