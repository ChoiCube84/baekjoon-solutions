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

	ll N, M, K;
	cin >> N >> M >> K;

	cout << ((N % (K - M) == 0) ? (N / (K - M)) : (N / (K - M) + 1));

	return 0;
}