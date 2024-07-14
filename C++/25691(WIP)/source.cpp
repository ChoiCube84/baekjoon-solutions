#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> graph(n);
    
    for (int i=0; i<n-1; i++) {
        int p, c;
        cin >> p >> c;

        graph[p].emplace_back(c);
    }

    vector<bool> apple(n, false);
    
    for (int i=0; i<n; i++) {
        int appleExist;
        cin >> appleExist;

        if (appleExist == 1) {
            apple[i] = true;
        }
    }
    
    return 0;
}

int dfs(int curr, int depth, int k, vector<vector<int>>& graph, vector<bool> apple) {
    int result = 0;
    
    if (apple[curr]) {
        result++;
        apple[curr] = false;
    }

    if (depth < k-1) {
        for (auto& next : graph[curr]) {
            result += dfs(next, depth+1, apple);
        }
    }
    
    return result;
}