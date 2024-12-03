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
	
	ll total = 0;
	
	while (N--) {
		ll horizontal, vertical;
		cin >> horizontal >> vertical;
		
		switch (horizontal) {
			case 136:
				total += 1000;
				break;
			case 142:
				total += 5000;
				break;
			case 148:
				total += 10000;
				break;
			case 154:
				total += 50000;
				break;
		}
	}
	
	cout << total;
	
	return 0;
}