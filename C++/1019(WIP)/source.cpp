#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

void update(vector<ull>& counts, ull N);
void zeroPaddedUpdate(vector<ull>& counts, ull N);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ull N;
	cin >> N;

	vector<ull> counts(10, 0);

	update(counts, N);

	for (auto& count : counts) {
		cout << count << ' ';
	}

	return 0;
}

void update(vector<ull>& counts, ull N) {
	if (N == 0) {
		return ;
	}
	else if (N < 10) {
		for (ull i=1; i<N; i++) {
			counts[i]++;
		}
	}
	else {
		ull digits = static_cast<ull>(log10l(N));
		ull powOf10 = static_cast<ull>(powl(10, digits));
		ull MSB = N / powOf10;

		update(counts, powOf10-1);
		for (ull i=1; i<=MSB-1; i++) {
			counts[i] += powOf10;

			for (ull j=0; j<10; j++) {
				zeroPaddedUpdate(counts, powOf10-1);
			}
		}

		counts[MSB] += N - (MSB * powOf10) + 1;

		zeroPaddedUpdate(counts, N - (MSB * powOf10));
	}
}

void zeroPaddedUpdate(vector<ull>& counts, ull N) {
	if (N < 10) {
		for (ull i=0; i<N; i++) {
			counts[i]++;
		}
	}
	else {
		ull digits = static_cast<ull>(log10l(N));
		ull powOf10 = static_cast<ull>(powl(10, digits));
		ull MSB = N / powOf10;

		for (ull i=0; i<=MSB-1; i++) {
			counts[i] += powOf10;

			for (ull j=0; j<10; j++) {
				zeroPaddedUpdate(counts, powOf10-1);
			}
		}

		counts[MSB] += N - (MSB * powOf10) + 1;

		zeroPaddedUpdate(counts, N - (MSB * powOf10));
	}
}