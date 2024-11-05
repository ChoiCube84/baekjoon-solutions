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
	
	ll total = 0;
	
	for (ll i=0; i<5; i++) {
		ll score;
		cin >> score;
		
		total += max(40LL, score);
	}
	
	cout << total / 5;
	
	return 0;
}