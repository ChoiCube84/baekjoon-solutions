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
	
	for (ll i=0; i<3; i++) {
		ll h1, m1, s1, h2, m2, s2;
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		
		ll h = h2 - h1;
		ll m = m2 - m1;
		ll s = s2 - s1;
		
		if (m < 0) {
			h--;
			m += 60;
		}
		
		if (s < 0) {
			m--;
			s += 60;
			
			if (m < 0) {
				h--;
				m += 60;
			}
		}
		
		cout << h << ' ' << m << ' ' << s << '\n';
	}
	
	return 0;
}