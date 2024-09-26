#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct cmp {
    bool operator()(const pll& a, const pll& b) const {
        return a.second < b.second;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pll>> graph(n+1);

    for (int i=0; i<m; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;

        graph[start].emplace_back(make_pair(end, weight));
        graph[end].emplace_back(make_pair(start, weight));
    }

    int s, t;
    cin >> s >> t;

    vector<int> table(n+1, INT_MAX);
    table[s] = 0;

    std::priority_queue<pll, vector<pll>, cmp> pq;
    pq.emplace(s, 0);

    while (!pq.empty()) {
        pll curr = pq.top();
        pq.pop();

        if (curr.second > table[curr.first]) {
            continue;
        }

        for (auto& next : graph[curr.first]) {
            if (curr.second + next.second < table[next.first]) {
                table[next.first] = curr.second + next.second;
                pq.emplace(next.first, table[next.first]);
            }
        }
    }

    cout << table[t];

    return 0;
}