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

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1 ,1};

int pack(int y, int x, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M, 0));

    for (int i=0; i<N; i++) {
        string input;
        cin >> input;

        for (int j=0; j<M; j++) {
            switch (input[j]) {
                case 'U':
                    grid[i][j] = 0;
                    break;
                case 'D':
                    grid[i][j] = 1;
                    break;
                case 'L':
                    grid[i][j] = 2;
                    break;
                case 'R':
                    grid[i][j] = 3;
                    break;
                default:
                    break;
            }
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<bool> isGroupNumber(N * M + 1, false);

    DisjointSet diset(N * M + 1, 1);
    stack<pair<pii, int>> s;
    int result = 0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            s.emplace(make_pair(i, j), 0);
        }
    }

    while (!s.empty()) {
        auto curr = s.top();
        s.pop();

        auto currPos = curr.first;
        int groupNum = curr.second;

        int currY = currPos.first;
        int currX = currPos.second;

        if (!visited[currY][currX]) {
            visited[currY][currX] = true;

            int dir = grid[currY][currX];

            int nextY = currY + dy[dir];
            int nextX = currX + dx[dir];

            if (groupNum == 0) {
                result++;
                groupNum = pack(currY, currX, M);
                isGroupNumber[groupNum] = true;
            }

            int nextGroupNum = diset.find(pack(nextY, nextX, M));

            if (groupNum != nextGroupNum) {
                diset.merge(groupNum, nextGroupNum);

                if (isGroupNumber[nextGroupNum]) {
                    result--;
                }
                else {
                    s.emplace(make_pair(nextY, nextX), diset.find(groupNum));
                }
            }
        }
    }

    cout << result;

    return 0;
}

int pack(int y, int x, int M) {
    return y * M + x + 1;
}
