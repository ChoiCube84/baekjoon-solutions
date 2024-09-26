#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int>> edges;
int shortestPath[501] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;

	while (TC--) {
		int N, M, W;
		cin >> N >> M >> W;

		edges.clear();

		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;

			edges.emplace_back(make_tuple(S, E, T));
			edges.emplace_back(make_tuple(E, S, T));
		}

		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;

			edges.emplace_back(make_tuple(S, E, -T));
		}

		shortestPath[1] = 0;
		for (int i = 2; i <= N; i++) {
			shortestPath[i] = 1000000;
		}

		for (int i = 1; i < N; i++) {
			for (auto edge : edges) {
				int start = get<0>(edge);
				int end = get<1>(edge);
				int length = get<2>(edge);

				shortestPath[end] = min(shortestPath[end], shortestPath[start] + length);
			}
		}
		
		bool negativeCycleExists = false;

		for (auto edge : edges) {
			int start = get<0>(edge);
			int end = get<1>(edge);
			int length = get<2>(edge);

			if (shortestPath[end] > shortestPath[start] + length) {
				negativeCycleExists = true;
				break;
			}
		}

		if (negativeCycleExists) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
