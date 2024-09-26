#include <bits/extc++.h>
#include "custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ull N, M, MOD = 1000000007;
	cin >> N >> M;

	ull result;

	if (N == 1 && M == 1) {
		result = 1;
	}
	else if (N * M % 3 == 1) {
		result = common::power(3, (N * M / 3) - 1, MOD);
		result = result * 4 % MOD;
	}
	else if (N * M % 3 == 2) {
		result = common::power(3, N * M / 3, MOD);
		result = result * 2 % MOD;
	}
	else {
		result = common::power(3, N * M / 3, MOD);
	}

	cout << result;

	return 0;
}