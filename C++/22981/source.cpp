#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ull N, K;
	cin >> N >> K;

	vector<ull> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ull maximum = 1;

	for (ull i=0; i<N-1; i++) {
		maximum = max(maximum, v[0] * (i + 1) + v[i + 1] * (N - i - 1));
	}

	if (K % maximum == 0) {
		cout << (K / maximum);
	}
	else {
		cout << (K / maximum) + 1;
	}

	return 0;
}