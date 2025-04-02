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
	
	ll T;
	cin >> T;

	while (T--) {
		ll result = 0;
		ll inside = 0;
		
		ll M;
		cin >> M;

		while (M--) {
			ll P1, P2;
			cin >> P1 >> P2;

			inside += P2;
			inside -= P1;

			if (inside > 0) {
				result = max(result, inside);
			}
		}

		cout << result << '\n';
	}
	
	return 0;
}