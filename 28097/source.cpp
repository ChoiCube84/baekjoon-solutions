#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long N;
	cin >> N;

	long sum = 8 * (N - 1);

	while (N--) {
		long temp;
		cin >> temp;

		sum += temp;
	}

	cout << sum / 24 << ' ' << sum % 24;

	return 0;
}