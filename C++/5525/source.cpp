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

	ll N, M;
	string S;

	cin >> N >> M >> S;

	ll streak = 0;
	ll patternCount = 0;
	
	for (int i = 0; i < M - 2; i++) {
		if (S[i] == 'I' && S[i + 1] == 'O' && S[i + 2] == 'I') {
			i++;
			streak++;

			if (streak == N) {
				streak--;
				patternCount++;
			}
		}
		else {
			streak = 0;
		}
	}

	cout << patternCount;

	return 0;
}