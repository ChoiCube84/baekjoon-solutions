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
	
	ll count = 0;
	
	while (N--) {
		char d, minus;
		ll days;
		
		cin >> d >> minus >> days;
		
		if (days <= 90) {
			count++;
		}
	}
	
	cout << count;
	
	return 0;
}