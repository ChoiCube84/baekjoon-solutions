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

#ifndef __KNAPSACK_HPP__
#define __KNAPSACK_HPP__

#include <vector>

template <typename T>
T knapsack(const std::vector<T>& weight, const std::vector<T>& value, const T& maxWeight) {
    if (weight.size() != value.size()) {
        return static_cast<T>(0);
    }

    size_t n = weight.size();
    std::vector<std::vector<T>> dp(n + 1, std::vector<T>(maxWeight + 1, 0));

    for (size_t i=1; i<=n; i++) {
        for (T w=0; w<=maxWeight; w++) {
            T without = dp[i-1][w];

            if (weight[i - 1] <= w) {
                T with = value[i-1] + dp[i-1][w - weight[i-1]];
                dp[i][w] = with > without ? with : without;
            }
            else {
                dp[i][w] = without;
            }
        }
    }

    return dp[n][maxWeight];
}

#endif //__KNAPSACK_HPP__

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> c(N+1, 0);

    for (int i=1; i<=N; i++) {
        cin >> c[i];
    }

    DisjointSet diset(N+1, 0);

    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;

        diset.merge(a, b);
    }

    vector<int> groupedChildren(N+1, 0);
    vector<int> groupedCandies(N+1, 0);

    vector<int> groupNumbers;

    for (int i=1; i<=N; i++) {
        int curr = diset.find(i);

        if (groupedCandies[curr] == 0) {
            groupNumbers.emplace_back(curr);
        }

        groupedChildren[curr] += 1;
        groupedCandies[curr] += c[i];
    }

    vector<int> candies;
    vector<int> children;

    for (auto& index : groupNumbers) {
        children.emplace_back(groupedChildren[index]);
        candies.emplace_back(groupedCandies[index]);
    }

    cout << knapsack<int>(children, candies, K - 1);

    return 0;
}
