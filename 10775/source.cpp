#include <bits/stdc++.h>

#ifndef __DISJOINT_SET_HPP__
#define __DISJOINT_SET_HPP__

#include <vector>

class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DisjointSet(int n, int order = 0) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = i * order;
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

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int G, P;
    cin >> G >> P;

    vector<int> g(P, 0);
    for (int i=0; i<P; i++) {
        cin >> g[i];
    }

    DisjointSet diset(G+1, -1);
    int result = 0;

    for (int i=0; i<P; i++) {
        int gate = diset.find(g[i]);
        if (gate != 0) {
            result++;
            diset.merge(gate - 1, gate);
        }
        else {
            break;
        }
    }

    cout << result;

    return 0;
}
