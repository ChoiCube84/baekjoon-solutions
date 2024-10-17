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
	
	string input;
	cin >> input;
	
	ll result = 0;
	
	for (ll i=0; i<input.size()-3; i++) {
		if (input[i] == 'D' && input[i+1] == 'K' && input[i+2] == 'S' && input[i+3] == 'H') {
			result++;
			i += 3;
		}
	}
	
	cout << result;
	
	return 0;
}