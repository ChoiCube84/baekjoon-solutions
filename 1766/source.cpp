#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1);
    vector<int> entryDeg(N+1, 0);

    for (int i=0; i<M; i++) {
        int former, latter;
        cin >> former >> latter;

        graph[former].emplace_back(latter);
        entryDeg[latter]++;
    }

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i=1; i<=N; i++) {
        if (entryDeg[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();

        if (entryDeg[curr] == 0) {
            cout << curr << " ";

            for (auto& next : graph[curr]) {
                entryDeg[next]--;

                if (entryDeg[next] == 0) {
                    pq.push(next);
                }
            }
        }
    }

    return 0;
}
