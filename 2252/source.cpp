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
        int A, B;
        cin >> A >> B;

        graph[A].emplace_back(B);
        entryDeg[B]++;
    }

    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (entryDeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto next : graph[curr]) {
            entryDeg[next]--;
            if (entryDeg[next] == 0) {
                q.push(next);
            }
        }

        cout << curr << " ";
    }

    return 0;
}
