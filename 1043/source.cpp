#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
private:
	std::vector<int> parent;
	std::vector<int> rank;

public:
	DisjointSet(int n) {
		parent.resize(n);
		rank.resize(n, 0);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) {
			return u;
		}
		else {
			return parent[u] = find(parent[u]);
		}
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u != v) {
			if (rank[u] > rank[v]) {
				std::swap(u, v);
			}

			parent[u] = v;

			if (rank[u] == rank[v]) {
				rank[v]++;
			}
		}
	}
};

queue<vector<int>> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, truthKnowers, truthGroup = -1;
	cin >> N >> M;

	DisjointSet diset(N);

	cin >> truthKnowers;
	for (int i = 0; i < truthKnowers; i++) {
		int tempPerson;
		cin >> tempPerson;
		tempPerson--;

		if (truthGroup == -1) {
			truthGroup = tempPerson;
		}
		else {
			diset.merge(tempPerson, truthGroup);
		}
	}

	for (int i = 0; i < M; i++) {
		int peopleCount, leader = -1;
		cin >> peopleCount;

		vector<int> tempVector;

		tempVector.emplace_back(peopleCount);
		
		for (int j = 0; j < peopleCount; j++) {
			int tempPerson;
			cin >> tempPerson;
			tempPerson--;
			
			tempVector.emplace_back(tempPerson);

			if (leader == -1) {
				leader = tempPerson;
			}
			else {
				diset.merge(leader, tempPerson);
			}
		}

		q.push(tempVector);
	}
	
	int answer = 0;

	while (!q.empty()) {
		vector<int> party = q.front();
		q.pop();

		answer++;
		
		for (int i = 1; i <= party[0]; i++) {
			if (truthGroup != -1 && diset.find(truthGroup) == diset.find(party[i])) {
				answer--;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}
