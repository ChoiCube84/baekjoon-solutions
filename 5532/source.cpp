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
	
	ll L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;
	
	if (A % C == 0) {
		A--;
	}
	
	if (B % D == 0) {
		B--;
	}
	
	cout << L - max(A / C + 1, B / D + 1);
	
	return 0;
}