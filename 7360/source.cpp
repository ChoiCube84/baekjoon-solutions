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
	
	ll n;
		
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		
		vector<ll> A(n);
		vector<ll> B(n);
		
		ll score_A = 0;
		ll score_B = 0;
		
		for (ll i=0; i<n; i++) {
			cin >> A[i];
		}
		for (ll i=0; i<n; i++) {
			cin >> B[i];
		}
		
		for (ll i=0; i<n; i++) {
			if (A[i] > B[i]) {
				if (A[i] - B[i] == 1) {
					if (A[i] == 2 && B[i] == 1) {
						score_B += 6;
					}
					else {
						score_B += (A[i] + B[i]);
					}
				}
				else {
					score_A += A[i];
				}
			}
			else if (A[i] < B[i]) {
				if (B[i] - A[i] == 1) {
					if (A[i] == 1 && B[i] == 2) {
						score_A += 6;
					}
					else {
						score_A += (A[i] + B[i]);
					}
				}
				else {
					score_B += B[i];
				}
			}
		}
		
		cout << "A has " << score_A <<" points. B has " << score_B << " points." << '\n' << '\n';
	}
	
	return 0;
}