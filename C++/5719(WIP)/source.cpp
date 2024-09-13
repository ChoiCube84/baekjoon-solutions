#include <bits/extc++.h>
#include "../custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

bool solve(void);

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
	
	gp_hash_table<ll, gp_hash_table<ll, ll>> table;
	
	while (M--) {
		ll U, V, P;
		cin >> U >> V >> P;
		
		table[U][V] = P;
	}
	
	auto result = shortest_path::dijkstra::getShortestPath(table, S);
	
	cout << result[D] << '\n';
	
	return true;
}