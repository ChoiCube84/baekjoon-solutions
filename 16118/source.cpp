#include <bits/extc++.h>
#include "custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll N, M;
	cin >> N >> M;
	
	gp_hash_table<ll, gp_hash_table<ll, ll>> fox_graph;
	gp_hash_table<ll, gp_hash_table<ll, ll>> wolf_graph;
	
	for (ll i=1; i<=N; i++) {
		fox_graph[i][i] = 0;
		
		wolf_graph[i][i] = 0;
		wolf_graph[i+N][i+N] = 0;
	}
	
	for (ll i=0; i<M; i++) {
		ll a, b, d;
		cin >> a >> b >> d;
		
		d *= 2;
		
		fox_graph[a][b] = d;
		fox_graph[b][a] = d;
		
		wolf_graph[a][b+N] = d / 2;
		wolf_graph[a+N][b] = d * 2;
		
		wolf_graph[b][a+N] = d / 2;
		wolf_graph[b+N][a] = d * 2;
	}
	
	auto fox_result = shortest_path::dijkstra::GetShortestPath(fox_graph, 1LL);
	auto wolf_result = shortest_path::dijkstra::GetShortestPath(wolf_graph, 1LL);
	
	ll result = 0;
	
	for (ll i=2; i<=N; i++) {
		if (fox_result.find(i) != fox_result.end()) {
			if (wolf_result.find(i) != wolf_result.end()) {
				if (wolf_result.find(i+N) != wolf_result.end()) {
					if (fox_result[i] < min(wolf_result[i], wolf_result[i+N])) {
						result++;
					}
				}
				else {
					if (fox_result[i] < wolf_result[i]) {
						result++;
					}
				}
			}
			else if (wolf_result.find(i+N) != wolf_result.end()) {
				if (fox_result[i] < wolf_result[i+N]) {
					result++;
				}
			}
			else {
				result++;
			}
		}
	}
	
	cout << result;
	
	return 0;
}