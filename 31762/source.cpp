#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

bool Detect(const string& str, char symbol);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll R, C, K;
	cin >> R >> C >> K;
	
	for (ll i=0; i<R; i++) {
		string M, P;
		cin >> M >> P;
		
		if (Detect(M, '-') && Detect(P, '*')) {
			cout << 'N';
			return 0;
		}
	}
	
	cout << 'Y';
	
	return 0;
}

bool Detect(const string& str, char symbol) {
	for (auto c : str) {
		if (c == symbol) {
			return true;
		}
	}
	
	return false;
}