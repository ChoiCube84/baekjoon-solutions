#include <bits/extc++.h>
#include "../custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

using Graph = vector<vector<pll>>;

bool solve(void);
void RemoveShortestPaths(Graph& graph, const Graph& reversed_graph, const vector<ll>& dist, ll curr, vector<bool>& visited);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve());
	
	return 0;
}

bool solve(void) {
	ll N, M;
	cin >> N >> M;

	if (N == 0 && M == 0) {
		return false;
	}

	ll S, D;
	cin >> S >> D;
	
	Graph graph(N), reversed_graph(N);
	
	while (M--) {
		ll U, V, P;
		cin >> U >> V >> P;
		
		graph[U].emplace_back(make_pair(V, P));
		reversed_graph[V].emplace_back(make_pair(U, P));
	}
	
	auto result = shortest_path::dijkstra::GetShortestPath(graph, S);
	vector<bool> visited(N, false);
		
	RemoveShortestPaths(graph, reversed_graph, result, D, visited);
	
	result = shortest_path::dijkstra::GetShortestPath(graph, S);
	
	cout << result[D] << '\n';
	
	return true;
}

void RemoveShortestPaths(Graph& graph, const Graph& reversed_graph, const vector<ll>& dist, ll curr, vector<bool>& visited) {
	if (visited[curr]) return;
    visited[curr] = true;
	
    for (auto [prev, weight] : reversed_graph[curr]) {
		if (dist[prev] != -1 && dist[prev] + weight == dist[curr]) {
			graph[prev].erase(remove(graph[prev].begin(), graph[prev].end(), make_pair(curr, weight)), graph[prev].end());
			RemoveShortestPaths(graph, reversed_graph, dist, prev, visited);
		}
    }
}