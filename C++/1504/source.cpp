#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int> a, const pair<int, int> b) {
        return a.second > b.second;
    }
};

vector<unordered_map<int, int>> graph(801);
int shortest[3][801] = {0,};
int visited[801] = {0,};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, E;
    int starts[3] = {1, 0, 0};

    cin >> N >> E;

    for (int i=0; i<E; i++) {
        int start, end, weight;

        cin >> start >> end >> weight;
        graph[start][end] = graph[end][start] = weight;
    }

    cin >> starts[1] >> starts[2];

    for (int s=0; s<3; s++) {
        for (int i=1; i<=N; i++) {
            shortest[s][i] = INT_MAX;
            if (i == starts[s]) {
                shortest[s][i] = 0;
            }
            visited[i] = false;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        pq.emplace(starts[s], 0);

        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();

            if (visited[curr.first] == false) {
                visited[curr.first] = true;

                for (auto& next : graph[curr.first]) {
                    if (curr.second + next.second < shortest[s][next.first]) {
                        shortest[s][next.first] = curr.second + next.second;
                        pq.emplace(next.first, shortest[s][next.first]);
                    }
                }
            }
        }
    }

    if ((shortest[0][starts[1]] == INT_MAX || shortest[1][starts[2]] == INT_MAX || shortest[2][N] == INT_MAX)
    && (shortest[0][starts[2]] == INT_MAX || shortest[2][starts[1]] == INT_MAX || shortest[1][N] == INT_MAX)) {
        cout << -1;
    }
    else {
        cout << min(shortest[0][starts[1]] + shortest[1][starts[2]] + shortest[2][N],
                    shortest[0][starts[2]] + shortest[2][starts[1]] + shortest[1][N]);
    }

    return 0;
}
