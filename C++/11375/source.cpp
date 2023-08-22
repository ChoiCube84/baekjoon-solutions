#include <bits/stdc++.h>

using namespace std;

bool visited[1002] = { 0, };

int assignedWork[1002] = { 0, };
int getWorker[1002] = { 0, };

vector<int> graph[1002];

bool match(int worker);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, answer = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int numberOfWorks;
		cin >> numberOfWorks;

		while (numberOfWorks--) {
			int workNumber;
			cin >> workNumber;
			
			graph[i].emplace_back(workNumber);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		answer += match(i);
	}

	cout << answer;

	return 0;
}

bool match(int worker) {
	if (visited[worker] == false) {
		visited[worker] = true;
		for (auto possibleWork : graph[worker]) {
			if (getWorker[possibleWork] == 0 || match(getWorker[possibleWork])) {
				assignedWork[worker] = possibleWork;
				getWorker[possibleWork] = worker;
				return 1;
			}
		}
	}
	return 0;
}
