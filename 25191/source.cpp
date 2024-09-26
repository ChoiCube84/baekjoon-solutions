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

	ll N, A, B;
	cin >> N >> A >> B;

	cout << min(N, A/2+B);
	
	return 0;
}