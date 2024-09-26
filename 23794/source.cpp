#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll N;
	cin >> N;
	
	for (ll i=0; i<N+2; i++) {
		cout << '@';
	}
	cout << '\n';
	
	for (ll i=0; i<N; i++) {
		cout << '@';
		for (ll i=0; i<N; i++) {
			cout << ' ';
		}
		cout << '@' << '\n';
	}
	
	for (ll i=0; i<N+2; i++) {
		cout << '@';
	}
	
	return 0;
}