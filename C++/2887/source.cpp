#include <bits/stdc++.h>

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

using namespace std;

struct Pos {
    int num;

    int x;
    int y;
    int z;
};

struct Edge {
    int v1;
    int v2;
    int weight;

    Edge(const Pos& A, const Pos& B) : v1(A.num), v2(B.num) {
        int dx = abs(A.x - B.x);
        int dy = abs(A.y - B.y);
        int dz = abs(A.z - B.z);

        weight = min({dx, dy, dz});
    }

    bool operator>(const Edge& other) const {
        return (this->weight > other.weight);
    }
};

struct cmp_x {
    bool operator()(const Pos& A, const Pos& B) {
        return (A.x < B.x);
    }
};

struct cmp_y {
    bool operator()(const Pos& A, const Pos& B) {
        return (A.y < B.y);
    }
};

struct cmp_z {
    bool operator()(const Pos& A, const Pos& B) {
        return (A.z < B.z);
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<Pos> points_x, points_y, points_z;
    vector<bool> visited(N, false);

    for (int i=0; i<N; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        points_x.push_back({i, x, y, z});
        points_y.push_back({i, x, y, z});
        points_z.push_back({i, x, y, z});
    }

    sort(points_x.begin(), points_x.end(), cmp_x());
    sort(points_y.begin(), points_y.end(), cmp_y());
    sort(points_z.begin(), points_z.end(), cmp_z());

    priority_queue<Edge, vector<Edge>, greater<>> pq;
    DisjointSet diset(N);
    unsigned long long result = 0;

    for (int i=0; i<N-1; i++) {
        pq.emplace(points_x[i], points_x[i+1]);
        pq.emplace(points_y[i], points_y[i+1]);
        pq.emplace(points_z[i], points_z[i+1]);
    }

    while (!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        if (diset.find(curr.v1) != diset.find(curr.v2)) {
            result += curr.weight;
            diset.merge(curr.v1, curr.v2);
        }
    }

    cout << result;

    return 0;
}
