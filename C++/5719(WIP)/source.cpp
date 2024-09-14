#include <bits/extc++.h>
#include "../custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

using Graph = gp_hash_table<ll, gp_hash_table<ll, ll>>;

bool solve(void);
void RemoveShortestPaths(Graph& graph, Graph& reversed_graph, gp_hash_table<ll, ll>& dist, ll curr, vector<bool>& visited);

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
	
	Graph graph, reversed_graph;
	
	while (M--) {
		ll U, V, P;
		cin >> U >> V >> P;
		
		graph[U][V] = P;
		reversed_graph[V][U] = P;
	}
	
	auto result = shortest_path::dijkstra::getShortestPath(graph, S);
	vector<bool> visited(N, false);
		
	RemoveShortestPaths(graph, reversed_graph, result, D, visited);
	
	result = shortest_path::dijkstra::getShortestPath(graph, S);
	
	if (result.find(D) == result.end()) {
		cout << -1 << '\n';
	}
	else {
		cout << result[D] << '\n';
	}	
	
	return true;
}

void RemoveShortestPaths(Graph& graph, Graph& reversed_graph, gp_hash_table<ll, ll>& dist, ll curr, vector<bool>& visited) {
    if (visited[curr]) return;
    visited[curr] = true;
	
    for (auto& [prev, weight] : reversed_graph[curr]) {
		cout << "Checking " << prev << " to " << curr << '\n';
        if (dist.find(prev) != dist.end() && dist[prev] + weight == dist[curr]) {
            graph[prev].erase(curr);
			cout << "Just pruned " << prev << " to " << curr << '\n';
            RemoveShortestPaths(graph, reversed_graph, dist, prev, visited);
        }
    }
}