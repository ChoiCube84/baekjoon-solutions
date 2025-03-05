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
	
	ll M, N;
	cin >> M >> N;

	ll U, L, R, D;
	cin >> U >> L >> R >> D;

	vector<string> letters(M);

	for (ll i=0; i<M; i++) {
		cin >> letters[i];
	}

	for (ll row=0; row<U+M+D; row++) {
		if (row < U) {
			for (ll col=0; col<L+N+R; col++) {
				if ((row+col) % 2 == 0) {
					cout << '#';
				}
				else {
					cout << '.';
				}
			}
		}
		else if (row < U+M) {
			for (ll col=0; col<L+N+R; col++) {
				if (col < L) {
					if ((row+col) % 2 == 0) {
						cout << '#';
					}
					else {
						cout << '.';
					}
				}
				else if (col < L+N) {
					cout << letters[row-U][col-L];
				}
				else {
					if ((row+col) % 2 == 0) {
						cout << '#';
					}
					else {
						cout << '.';
					}
				}
			}
		}
		else {
			for (ll col=0; col<L+N+R; col++) {
				if ((row+col) % 2 == 0) {
					cout << '#';
				}
				else {
					cout << '.';
				}
			}
		}
		cout << '\n';
	}
	
	return 0;
}