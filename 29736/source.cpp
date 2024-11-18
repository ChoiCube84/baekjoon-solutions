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
	
	ll A, B;
	cin >> A >> B;
	
	ll K, X;
	cin >> K >> X;
	
	ll result = min(B, K + X) - max(A, K - X) + 1;
	
	if (result > 0) {
		cout << result;
	}
	else {
		cout << "IMPOSSIBLE";
	}
	
	return 0;
}