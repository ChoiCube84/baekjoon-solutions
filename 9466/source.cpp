#include <bits/stdc++.h>

using namespace std;

void simulate();
void search(int start, const vector<int>& graph, vector<int>& result);

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
    int n, alone = 0;
    cin >> n;

    vector<int> graph(n+1, 0);
    vector<int> result(n+1, 0);

    for (int i=1; i<=n; i++) {
        cin >> graph[i];
    }

    for (int i=1; i<=n; i++) {
        if (result[i] == 0) {
            search(i, graph, result);
        }
    }

    for (int i=1; i<=n; i++) {
        if (result[i] == -1) {
            alone++;
        }
    }

    cout << alone << "\n";
}

void search(int start, const vector<int>& graph, vector<int>& result) {
    int n = result.size() - 1;
    vector<bool> visited(n + 1, false);

    int curr = start;

    while (!visited[curr] && result[curr] == 0) {
        visited[curr] = true;
        curr = graph[curr];
    }

    if (curr == start) {
        result[start] = 1;
        for (curr = graph[start]; curr != start; curr = graph[curr]) {
            result[curr] = 1;
        }
    }
    else {
        result[start] = -1;
        for (int fail = graph[start]; fail != curr; fail = graph[fail]) {
            result[fail] = -1;
        }

        if (result[curr] == 0) {
            start = curr;
            result[start] = 1;
            for (curr = graph[start]; curr != start; curr = graph[curr]) {
                result[curr] = 1;
            }
        }
    }
}
