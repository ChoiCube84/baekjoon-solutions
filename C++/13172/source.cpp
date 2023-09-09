#include <bits/stdc++.h>

using namespace std;

long long int power(long long int base, long long int exponent, long long int mod);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	constexpr long long int mod = 1000000007;

	long long int M;
	cin >> M;

	long long int total = 0;

	while (M--) {
		long long int N, S;
		cin >> N >> S;

		total += (S * power(N, mod - 2, mod)) % mod;
	}

	cout << total % mod;

	return 0;
}

long long int power(long long int base, long long int exponent, long long int mod) {
	long long int result = 1;

	while (exponent) {
		if (exponent % 2 == 1) {
			result = result * base % mod;
		}
		exponent = exponent / 2;
		base = base * base % mod;
	}

	return result;
}
