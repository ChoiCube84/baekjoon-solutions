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
	
	ll A, B;
	cin >> A >> B;
	
	ll C;
	cin >> C;
	
	ll sum = A + B - 2 * C;
	
	if (sum < 0) {
		sum += (2 * C);
	}
	
	cout << sum;
	
	return 0;
}