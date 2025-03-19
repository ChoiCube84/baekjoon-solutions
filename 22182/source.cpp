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
	
	ll n;
	ld r;
	
	const ld PI = 3.141592653589793L;

	cin >> n >> r;

	ld area = PI * r * r;

	vector<ll> a(n);
	ll sum = 0;

	for (ll i=0; i<n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	cout << fixed;
	cout << setprecision(15);

	for (auto& i : a) {
		cout << area * static_cast<ld>(i) / static_cast<ld>(sum) << '\n';
	}
	
	return 0;
}