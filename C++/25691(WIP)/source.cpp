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

    int appleInfo = 0;
    for (int i=0; i<n; i++) {
        int apple;
        cin >> apple;

        if (apple == 1) {
            appleInfo += 1;
        }
        appleInfo <<= 1;
    }
    
    return 0;
}

int dfs(int curr) {
    return 0;
}