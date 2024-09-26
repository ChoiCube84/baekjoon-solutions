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
	
	ll result = -1;
	
	for (ll i=0; i<N; i++) {
		ll A, B;
		cin >> A >> B;
		
		if (A < B) {
			if (result == -1 || result > B) {
				result = B;
			}
		}
	}
	
	cout << result;
	
	return 0;
}