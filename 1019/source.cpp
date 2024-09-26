#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

void update(vector<ull>& counts, ull N);
void zeroPaddedUpdate(vector<ull>& counts, ull N, ull digits);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ull N;
	cin >> N;

	vector<ull> counts(10, 0);

	update(counts, N);

	for (ull i=0; i<10; i++) {
		cout << counts[i] << ' ';
	}

	return 0;
}

void update(vector<ull>& counts, ull N) { // Example: 723456
	if (N == 0) {
		return ;
	}
	else if (N < 10) {
		for (ull i=1; i<=N; i++) {
			counts[i]++;
		}
	}
	else {
		ull digits = static_cast<ull>(log10l(N)); // 5
		ull powOf10 = static_cast<ull>(powl(10, digits)); // 100000
		ull MSB = N / powOf10; // 7

		update(counts, powOf10-1); // 1 ~ 99999
		for (ull i=1; i<MSB; i++) { // 100000 ~ 199999, 200000 ~ 299999, ..., 600000 ~ 699999
			counts[i] += powOf10;

			for (ull j=0; j<10; j++) {
				counts[j] += powOf10 * digits / 10;
			}
		}

		// 700000 ~ 723456
		counts[MSB] += N - (MSB * powOf10) + 1;
		zeroPaddedUpdate(counts, N - (MSB * powOf10), digits-1); // 00000 ~ 23456
	}
}

void zeroPaddedUpdate(vector<ull>& counts, ull N, ull digits) { // Example: 23456
	ull currentDigits = static_cast<ull>(log10l(N)); // 4

	if (N == 0) { // Example: 00000
		counts[0] += digits + 1;
	}
	else if (currentDigits < digits) { // Example: 00234
		counts[0] += (digits - currentDigits) * (N + 1); 

		zeroPaddedUpdate(counts, N, currentDigits);
	}
	else if (N < 10) {
		for (ull i=0; i<=N; i++) {
			counts[i]++;
		}
	}
	else {
		ull powOf10 = static_cast<ull>(powl(10, digits)); // 10000
		ull MSB = N / powOf10; // 2

		for (ull i=0; i<MSB; i++) { // 00000 ~ 09999, 10000 ~ 19999
			counts[i] += powOf10;

			for (ull j=0; j<10; j++) {
				counts[j] += powOf10 * digits / 10;
			}
		}

		// 20000 ~ 23456
		counts[MSB] += N - (MSB * powOf10) + 1; 
		zeroPaddedUpdate(counts, N - (MSB * powOf10), digits-1); // 0000 ~ 3456
	}
}