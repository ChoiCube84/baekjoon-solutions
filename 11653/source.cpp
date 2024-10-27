#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll N;
    cin >> N;
    
    if (N != 1) {
        for (ll i=2; i*i<N+1; i++) {
            while(N % i == 0) {
                cout << i << '\n';
                N /= i;
            }
        }
        
        if (N != 1) {
			cout << N;
		}
    }
	
	return 0;
}