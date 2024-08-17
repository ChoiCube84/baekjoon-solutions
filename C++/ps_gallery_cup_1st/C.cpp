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

	ll N, H, S;
	cin >> N >> H >> S;

	vector<ll> f(N);
	for (ll i=0; i<N; i++) {
		cin >> f[i];
	}

	ld centerHeight = static_cast<ld>(S) / N;

	ld leftTriangleForcePerHeight = 0.0L;
	ld rightTriangleForcePerHeight = 0.0L;

	if (N % 2 == 1) {
		for (ll coeff=1, i=((N-1)/2)-1; i>=0; coeff++, i--) {
			leftTriangleForcePerHeight += f[i] * coeff;
		}
		for (ll coeff=1, i=((N-1)/2)+1; i<N; coeff++, i++) {
			rightTriangleForcePerHeight += f[i] * coeff;
		}
	}
	else {
		for (ll coeff=1, i=((N/2)-1); i>=0; coeff++, i--) {
			leftTriangleForcePerHeight += f[i] * (static_cast<ld>(coeff) - 0.5L);
		}
		for (ll coeff=1, i=(N/2); i<N; coeff++, i++) {
			rightTriangleForcePerHeight += f[i] * (static_cast<ld>(coeff) - 0.5L);
		}
	}

	leftTriangleForcePerHeight = leftTriangleForcePerHeight * 2.0L / static_cast<ld>(N);
	rightTriangleForcePerHeight = rightTriangleForcePerHeight * 2.0L / static_cast<ld>(N);

	ld totalForce = 0.0L;

	for (ll i=0; i<N; i++) {
		totalForce += static_cast<ld>(f[i]) * centerHeight;
	}

	if (leftTriangleForcePerHeight > rightTriangleForcePerHeight) {
		totalForce -= (leftTriangleForcePerHeight - rightTriangleForcePerHeight) * min(centerHeight, static_cast<ld>(H) - centerHeight);
	}
	else if (leftTriangleForcePerHeight < rightTriangleForcePerHeight) {
		totalForce -= (rightTriangleForcePerHeight - leftTriangleForcePerHeight) * min(centerHeight, static_cast<ld>(H) - centerHeight);
	}

	cout << totalForce;

	return 0;
}