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
	
	N -= 10;
	
	ll result = 6;
	
	for (ll i=0; i<N; i++) {
		result *= (i + 11);
	}
	
	cout << result;
	
	return 0;
}