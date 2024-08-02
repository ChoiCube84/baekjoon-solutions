#include <bits/extc++.h>
#include "custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

void solve(void);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i=0; i<T; i++) {
		solve();
	}
	
	return 0;
}

void solve(void) {
	int N, M;
	cin >> N >> M;

	gp_hash_table<int, gp_hash_table<int, int>> graph;
	
	for (int i=0; i<M; i++) {
		int X, Y, D;
		cin >> X >> Y >> D;

		if (graph[X].find(Y) == graph[X].end() || graph[X][Y] > D) {
			graph[X][Y] = D;
		}
		if (graph[Y].find(X) == graph[Y].end() || graph[Y][X] > D) {
			graph[Y][X] = D;
		}
	}

	int S;
	cin >> S;

	vector<int> stopovers(S+1);
	stopovers[S] = 0;
	
	for (int i=0; i<S; i++) {
		cin >> stopovers[i];
	}
	
	gp_hash_table<int, gp_hash_table<int, int>> shortestPath;
		
	for (auto& start : stopovers) {
		gp_hash_table<int, int> temp = shortest_path::dijkstra::getShortestPath(graph, start);
		
		for (auto& stopover : stopovers) {
			shortestPath[start][stopover] = temp[stopover];
		}
	}

	stopovers.pop_back();

	int minimum = INT_MAX;
	
	do {
		int curr = 0;
		int candidate = 0;
		
		for (auto& stopover : stopovers) {
			candidate += shortestPath[curr][stopover];
			curr = stopover;
		}
		candidate += shortestPath[curr][0];
		
		minimum = min(minimum, candidate);
	} while (next_permutation(stopovers.begin(), stopovers.end()));

	cout << minimum << '\n';
}