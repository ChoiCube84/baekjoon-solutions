#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool isInRange(const pair<int, int>& pos, int N, int M);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> grid(N, vector<bool>(M, false));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> setNum(N, vector<int>(M, 0));
    vector<int> pointCounts;

    stack<pair<pair<int, int>, int>> s;

    for (int i=0; i<N; i++) {
        string input;
        cin >> input;

        for (int j=0; j<M; j++) {
            if (input[j] == '1') {
                grid[i][j] = true;
            }
            else {
                s.emplace(make_pair(i, j), -1);
            }
        }
    }

    while (!s.empty()) {
        auto temp = s.top();
        s.pop();

        pair<int, int> currPos = temp.first;
        int currSet = temp.second;

        if (!visited[currPos.first][currPos.second]) {
            if (currSet == -1) {
                currSet = pointCounts.size();
                pointCounts.emplace_back(0);
            }

            visited[currPos.first][currPos.second] = true;
            setNum[currPos.first][currPos.second] = currSet;
            pointCounts[currSet]++;

            for (int dir=0; dir<4; dir++) {
                pair<int, int> next = make_pair(currPos.first + dy[dir], currPos.second + dx[dir]);

                if (isInRange(next, N, M) && !grid[next.first][next.second]) {
                    s.emplace(next, currSet);
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (grid[i][j]) {
                int reachable = 1;
                vector<bool> checked(pointCounts.size(), false);

                for (int dir=0; dir<4; dir++) {
                    pair<int, int> adj = make_pair(i + dy[dir], j + dx[dir]);

                    if (isInRange(adj, N, M) && !grid[adj.first][adj.second]) {
                        int currSet = setNum[adj.first][adj.second];

                        if (!checked[currSet]) {
                            reachable += pointCounts[currSet];
                            checked[currSet] = true;
                        }
                    }
                }

                cout << reachable % 10;
            }
            else {
                cout << 0;
            }
        }
        cout << "\n";
    }

    return 0;
}

bool isInRange(const pair<int, int>& pos, int N, int M) {
    if (pos.first < 0 || pos.first > N - 1) {
        return false;
    }
    else if (pos.second < 0 || pos.second > M - 1) {
        return false;
    }
    else {
        return true;
    }
}
