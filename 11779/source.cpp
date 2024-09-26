#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct compare{
    bool operator()(const pair<int, int> a, const pair<int, int> b){
        return a.second > b.second;
    }
};

vector<unordered_map<int, int>> graph(1001);
pair<int, int> table[1001];

void dijkstra(int n, int departure, int arrival);
void retrace(int departure, int arrival);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, departure, arrival;

    cin >> n >> m;

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    for (int i=0; i<m; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;

        graph[start][end] = min(graph[start][end], weight);
    }

    cin >> departure >> arrival;

    dijkstra(n, departure, arrival);

    cout << table[arrival].first << "\n";
    retrace(departure, arrival);

    return 0;
}

void dijkstra(int n, int departure, int arrival) {
    bool visit[1001] = {false,};

    for (int i=1; i<n+1; i++) {
        table[i].first = INT_MAX;
        if (i == departure) table[i].first = 0;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.emplace(departure, 0);

    for (int i=0; i<n-1; i++) {
        if (pq.empty()) break;

        pair<int, int> curr = pq.top();
        pq.pop();

        visit[curr.first] = true;

        if (curr.second > table[curr.first].first) continue;

        for (auto& j : graph[curr.first]) {
            if (j.second != INT_MAX) {
                if (curr.second + j.second < table[j.first].first) {
                    table[j.first].first = curr.second + j.second;
                    table[j.first].second = curr.first;

                    pq.emplace(j.first, table[j.first].first);
                }
            }
        }
    }
}

void retrace(int departure, int arrival) {
    int curr = arrival;
    stack<int> s;

    while (curr != departure) {
        s.push(curr);
        curr = table[curr].second;
    }

    s.push(curr);
    cout << s.size() << "\n";

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
