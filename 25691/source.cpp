#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

gp_hash_table<ull, int> table;

ull combine(int curr, int depth, unsigned apple, unsigned visited);
int dfs(int curr, int depth, int k, const vector<pair<vector<int>, int>>& graph, unsigned apple, unsigned visited);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;    
    cin >> n >> k;

    vector<pair<vector<int>, int>> graph(n);
    graph[0].second = -1;

    for (int i=0; i<n-1; i++) {
        int p, c;
        cin >> p >> c;

        graph[p].first.emplace_back(c);
        graph[c].second = p;
    }

    unsigned apple = 0;

    for (int i=0; i<n; i++) {
        int appleExist;
        cin >> appleExist;

        if (appleExist == 1) {
            apple |= (1 << i);
        }
    }

    cout << dfs(0, 1, k, graph, apple, 0);

    return 0;
}

ull combine(int curr, int depth, unsigned apple, unsigned visited) {
    ull result = curr;
    result <<= 5;
    
    result += depth;
    result <<= 5;

    result += apple;
    result <<= 17;

    result += visited;

    return result;
}

int dfs(int curr, int depth, int k, const vector<pair<vector<int>, int>>& graph, unsigned apple, unsigned visited) {
    if (table.find(combine(curr, depth, apple, visited)) != table.end()) {
        return table[combine(curr, depth, apple, visited)];
    }
    
    int result = 0;

    visited |= (1 << curr);

    if (apple & (1 << curr)) {
        result++;
        apple &= ~(1 << curr);
    }

    if (depth < k) {
        int maximum = -1;

        for (auto& next : graph[curr].first) {
            if (visited & (1 << next)) {
                continue;
            }

            maximum = max(maximum, dfs(next, depth+1, k, graph, apple, visited));
        }

        if (maximum == -1) {
            if (graph[curr].second != -1) {
                result += dfs(graph[curr].second, depth, k, graph, apple, visited);
            }
        }
        else {
            result += maximum;
        }
    }

    table[combine(curr, depth, apple, visited)] = result;
    return result;
}