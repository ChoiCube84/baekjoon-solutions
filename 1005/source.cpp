#include <bits/stdc++.h>

using namespace std;

void simulate();

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        simulate();
    }

    return 0;
}

void simulate() {
    int N, K, W;
    cin >> N >> K;

    vector<int> buildingTime(N + 1);
    vector<int> result(N + 1, -1);

    vector<vector<int>> graph(N+1);
    vector<int> entryDeg(N+1, 0);

    for (int i=1; i<=N; i++) {
        cin >> buildingTime[i];
    }

    for (int i=0; i<K; i++) {
        int A, B;
        cin >> A >> B;

        graph[A].emplace_back(B);
        entryDeg[B]++;
    }

    cin >> W;

    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (entryDeg[i] == 0) {
            q.push(i);
            result[i] = buildingTime[i];
        }
    }

    bool resultFound = false;
    while (!q.empty() && !resultFound) {
        int curr = q.front();
        q.pop();

        for (auto next : graph[curr]) {
            entryDeg[next]--;
            result[next] = max(result[next], result[curr] + buildingTime[next]);

            if (entryDeg[next] == 0) {
                q.push(next);

                if (next == W) {
                    resultFound = true;
                    break;
                }
            }
        }
    }

    cout << result[W] << "\n";
}
