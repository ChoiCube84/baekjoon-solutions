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

    ull N, M, X;
    cin >> N >> M >> X;

    vector<ull> a(M, 0);
    vector<ull> buyCount(M, 0);
    
    for (ull i=0; i<M; i++) {
        cin >> a[i];
    }

    reverse(a.begin(), a.end());

    ull gotPresent = 0;
    for (ll i=M-1; i>=0; i--) {
        if (X == 0) {
            break;
        }
        else if (i == 0) {
            buyCount[i] = N - gotPresent;
            break;
        }

        ull nestEgg = (N - gotPresent - 1) * a[0];
        ull budget = X - nestEgg;
        
        if (budget >= a[i]) {
            ull presentCount = min((X - (N - gotPresent) * a[0]) / (a[i] - a[0]), N - gotPresent);
            
            buyCount[i] = presentCount;
            gotPresent += presentCount;

            X -= presentCount * a[i];
        }
    }
    
    reverse(buyCount.begin(), buyCount.end());

    for (int i=0; i<M; i++) {
        cout << buyCount[i] << " ";
    }
    
    return 0;
}