#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    vector<int> entryDeg(N+1, 0);

    for (int i=0; i<M; i++) {
        int singerCount;
        cin >> singerCount;

        int former, latter;
        cin >> latter;

        for (int j=0; j < singerCount - 1; j++) {
            former = latter;
            cin >> latter;

            graph[former].emplace_back(latter);
            entryDeg[latter]++;
        }
    }

    queue<int> q;
    vector<int> result;

    for (int i=1; i<=N; i++) {
        if (entryDeg[i] == 0) {
            q.emplace(i);
            result.emplace_back(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto& next : graph[curr]) {
            entryDeg[next]--;

            if (entryDeg[next] == 0) {
                q.push(next);
                result.emplace_back(next);
            }
        }
    }

    if (result.size() < N) {
        cout << 0;
    }
    else {
        for (auto& singer : result) {
            cout << singer << "\n";
        }
    }

    return 0;
}
