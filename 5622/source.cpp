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
	
	for (auto& c : input) {
		ll num = c - 'A';
		
		if (num < 3) {
			result += 3;
		}
		else if (num < 6) {
			result += 4;
		}
		else if (num < 9) {
			result += 5;
		}
		else if (num < 12) {
			result += 6;
		}
		else if (num < 15) {
			result += 7;
		}
		else if (num < 19) {
			result += 8;
		}
		else if (num < 22) {
			result += 9;
		}
		else {
			result += 10;
		}
	}
	
	cout << result;
	
	return 0;
}