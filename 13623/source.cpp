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
	
	ll A, B, C;
	cin >> A >> B >> C;
	
	if (A == B) {
		if (B == C) {
			cout << '*';
		}
		else {
			cout << 'C';
		}
	}
	else {
		if (B == C) {
			cout << 'A';
		}
		else {
			cout << 'B';
		}
	}
	
	return 0;
}