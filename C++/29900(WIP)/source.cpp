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

    int N;
    cin >> N;

    vector<int> M(N, 0);
    for (int i=0; i<N; i++) {
        cin >> M[i];
    }

    sort(M.begin(), M.end());

    // To be continued...
    
    return 0;
}