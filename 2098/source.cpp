#define INF 987654321
#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> graph(16, vector<int>(16, 0));
vector<vector<int>> dp(16, vector<int>(1 << 16, INF));
vector<vector<bool>> caseChecked(16, vector<bool>(1 << 16, false));

int TSP(int start, unsigned visited);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> graph[i][j];
        }
    }

    cout << TSP(0, 1);

    return 0;
}

int TSP(int start, unsigned visited) {
    if (!caseChecked[start][visited]) {
        caseChecked[start][visited] = true;

        if (visited == (1 << N) - 1) {
            if (graph[start][0] != 0) {
                dp[start][visited] = graph[start][0];
            }
        }
        else if (dp[start][visited] == INF) {
            for (int i=1; i<N; i++) {
                if (visited & (1 << i) || graph[start][i] == 0) {
                    continue;
                }
                else {
                    dp[start][visited] = min(dp[start][visited], TSP(i, visited | (1 << i)) + graph[start][i]);
                }
            }
        }
    }

    return dp[start][visited];
}
