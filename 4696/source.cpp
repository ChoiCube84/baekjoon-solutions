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
	
	ld n;
	
	cout << fixed;
	cout << setprecision(2);
	
	while (true) {
		cin >> n;
		
		if (n == 0) {
			break;
		}
		
		cout << 1 + n + n * n + n * n * n + n * n * n * n << '\n';
	}
	
	return 0;
}