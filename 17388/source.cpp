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
	
	ll S, K, H;
	cin >> S >> K >> H;
	
	if (S + K + H < 100) {
		if (S > K) {
			if (K > H) {
				cout << "Hanyang";
			}
			else {
				cout << "Korea";
			}
		}
		else {
			if (S < H) {
				cout << "Soongsil";
			}
			else {
				cout << "Hanyang";
			}
		}
	}
	else {
		cout << "OK";
	}
	
	return 0;
}