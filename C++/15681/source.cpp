#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

void setSubTreeNodeCount(int node, int parent, vector<vector<int>>& graph, vector<int>& dp);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, R, Q;
    cin >> N >> R >> Q;

    vector<vector<int>> graph(N+1);

    for (int i=0; i<N-1; i++) {
        int U, V;
        cin >> U >> V;

        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    vector<int> dp(N+1, 0);

    setSubTreeNodeCount(R, 0, graph, dp);

    for (int i=0; i<Q; i++) {
        int U;
        cin >> U;

        cout << dp[U] << "\n";
    }

    return 0;
}

void setSubTreeNodeCount(int node, int parent, vector<vector<int>>& graph, vector<int>& dp) {
    int N = graph.size() - 1;
    dp[node] = 1;

    for (int child : graph[node]) {
        if (child != parent) {
            setSubTreeNodeCount(child, node, graph, dp);
            dp[node] += dp[child];
        }
    }
}