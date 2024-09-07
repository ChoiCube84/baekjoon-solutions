#ifndef __DISJOINT_SET_HPP__
#define __DISJOINT_SET_HPP__

#include <vector>

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

#endif // !__DISJOINT_SET_HPP__
