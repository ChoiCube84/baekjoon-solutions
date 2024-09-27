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
	
	for (ll t=1; t<=N; t++) {
		ll row, col, w, h;
		cin >> row >> col >> w >> h;
		
		cout << "Case #" << t << ":" << '\n';
		for (ll i=0; i<row; i++) {
			cout << '+';
			for (ll j=0; j<col; j++) {
				for (ll k=0; k<w; k++) {
					cout << '-';
				}
				cout << '+';
			}
			
			for (ll l=0; l<h; l++) {
				cout << '\n';
				cout << '|';
				for (ll j=0; j<col; j++) {
					for (ll k=0; k<w; k++) {
						cout << '*';
					}
					cout << '|';
				}
			}
			cout << '\n';
		}
		cout << '+';
		for (ll j=0; j<col; j++) {
			for (ll k=0; k<w; k++) {
				cout << '-';
			}
			cout << '+';
		}
		cout << '\n';
	}
	
	return 0;
}