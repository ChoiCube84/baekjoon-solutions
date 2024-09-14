#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll M, F;
	
	while (true) {
		cin >> M >> F;
		
		if (M == 0 && F == 0) {
			break;
		}
		
		cout << M + F << '\n';
	}
	
	return 0;
}