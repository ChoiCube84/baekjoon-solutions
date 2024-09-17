#include <bits/extc++.h>
#include "custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

class Distance {
private:
	ll vertex_count;
	ll total_cost;
public:
	Distance(ll total_cost=0) : vertex_count(1), total_cost(total_cost) {}
	
	Distance operator+(const Distance& other) {
		Distance result;
		
		result.vertex_count = this->vertex_count + other.vertex_count;
		result.total_cost = this->total_cost + other.total_cost;
		
		return result;
	}
	
	bool operator<(const Distance& other) const {
		if (this->vertex_count < other.vertex_count) {
			return true;
		}
		else if (this->vertex_count > other.vertex_count) {
			return false;
		}
		else {
			return (this->total_cost < other.total_cost);
		}
	}
	
	ll GetCost(void) const {
		return total_cost;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll m, n;
	cin >> m >> n;
	
	gp_hash_table<ll, gp_hash_table<ll, Distance>> graph;
	
	while (n--) {
		ll src, dest, cost;
		cin >> src >> dest >> cost;
		
		graph[src][dest] = Distance(cost);
	}
	
	auto result = shortest_path::dijkstra::GetShortestPath(graph, 0LL);
	
	cout << result[1].GetCost();
	
	return 0;
}