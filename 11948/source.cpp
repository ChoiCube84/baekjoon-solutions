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
	
	ll A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	
	cout << (A + B + C + D) - min({A, B, C, D}) + max(E, F);
	
	return 0;
}