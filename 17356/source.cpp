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
	
	ld M = static_cast<ld>(B - A) / 400L;
	
	cout << fixed;
	cout << setprecision(15);
	
	cout << 1L / (1 + pow(10L, M));
	
	return 0;
}