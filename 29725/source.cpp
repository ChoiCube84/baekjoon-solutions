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
	
	ll score = 0;
	
	for (ll i=0; i<8; i++) {
		string input;
		cin >> input;
		
		for (ll j=0; j<8; j++) {
			switch (input[j]) {
				case 'P':
					score += 1;
					break;
				case 'p':
					score -= 1;
					break;
				case 'N':
				case 'B':
					score += 3;
					break;
				case 'n':
				case 'b':
					score -= 3;
					break;
				case 'R':
					score += 5;
					break;
				case 'r':
					score -= 5;
					break;
				case 'Q':
					score += 9;
					break;
				case 'q':
					score -= 9;
					break;
			}
		}
	}
	
	cout << score;
	
	return 0;
}