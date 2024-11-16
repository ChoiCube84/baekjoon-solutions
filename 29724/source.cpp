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
	
	ll mass = 0;
	ll value = 0;
	
	while (N--) {
		char T;
		ll W, H, L;
		
		cin >> T >> W >> H >> L;
		
		if (T == 'A') {
			ll apple_count = (W / 12) * (H / 12) * (L / 12);
			
			mass += (1000 + (apple_count * 500));
			value += (apple_count * 4000);
		}
		else {
			mass += 6000;
		}
	}
	
	cout << mass << '\n' << value;
	
	return 0;
}