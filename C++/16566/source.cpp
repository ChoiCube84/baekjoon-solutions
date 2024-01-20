#include <bits/stdc++.h>

#ifndef __DISJOINT_SET_HPP__
#define __DISJOINT_SET_HPP__

#include <vector>

class DisjointSet {
private:
    std::vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);

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

        if (u > v) {
            parent[v] = u;
        }
        else if (u < v) {
            parent[u] = v;
        }
    }
};

#endif // !__DISJOINT_SET_HPP__

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> myCards;
    vector<int> enemyCards;

    DisjointSet diset(4000001);

    for (int i=0; i<M; i++) {
        int temp;
        cin >> temp;
        myCards.emplace_back(temp);
    }

    for (int i=0; i<K; i++) {
        int temp;
        cin >> temp;
        enemyCards.emplace_back(temp);
    }

    sort(myCards.begin(), myCards.end());

    for (auto& card : enemyCards) {
        int myCardIndex = diset.find(upper_bound(myCards.begin(), myCards.end(), card) - myCards.begin());
        cout << myCards[myCardIndex] << "\n";
        diset.merge(myCardIndex, myCardIndex + 1);
    }

    return 0;
}
