#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct edge_cmp {
    bool operator()(const pii& A, const pii& B) {
        return A.second > B.second;
    }
};

ll prim (const vector<vector<pii>>& graph, int& maximum);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pii>> graph(N+1);

    for (int i=0; i<M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        graph[A].emplace_back(make_pair(B, C));
        graph[B].emplace_back(make_pair(A, C));
    }

    int maximum = 0;
    ll result = prim(graph, maximum);

    cout << result - maximum;

    return 0;
}

ll prim (const vector<vector<pii>>& graph, int& maximum) {
    size_t n = graph.size() - 1;

    priority_queue<pii, vector<pii>, edge_cmp> edges;
    vector<bool> visited(n+1, false);

    ll result = 0;

    edges.emplace(1, 0);

    for(int i=0; i<n; i++) {
        pii curr;

        do {
            curr = edges.top();
            edges.pop();
        } while (visited[curr.first]);

        visited[curr.first] = true;
        result += curr.second;

        maximum = max(maximum, curr.second);

        for (auto& next : graph[curr.first]) {
            if (!visited[next.first]) {
                edges.push(next);
            }
        }
    }

    return result;
}
