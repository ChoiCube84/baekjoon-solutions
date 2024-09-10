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
	
	ll A, B, C, D;
	cin >> A >> B >> C >> D;
	
	if (A == B && B == C && C == D) {
		cout << "Fish At Constant Depth";
	}
	else if (A < B && B < C && C < D) {
		cout << "Fish Rising";
	}
	else if (A > B && B > C && C > D) {
		cout << "Fish Diving";
	}
	else {
		cout << "No Fish";
	}
	
	return 0;
}