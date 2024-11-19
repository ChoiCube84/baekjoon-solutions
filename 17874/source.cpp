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
	
	ll n, h, v;
	cin >> n >> h >> v;
	
	cout << max(h, n-h) * max(v, n-v) * 4;
	
	return 0;
}