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
	
	string code;
	cin >> code;
	
	ll N;
	cin >> N;
	
	ll result = 0;
	
	while (N--) {
		string input;
		cin >> input;
		
		bool success = true;
		
		for (ll i=0; i<5; i++) {
			if (code[i] != input[i]) {
				success = false;
				break;
			}
		}
		
		if (success) result++;
	}
	
	cout << result;
	
	return 0;
}