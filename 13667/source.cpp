#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	
	while (true) {
		cin >> N;
		
		if (N == 0) {
			break;
		}

		while (N--) {
			int A, B, C, D, E;
			cin >> A >> B >> C >> D >> E;

			bool marked[5];

			marked[0] = (A <= 127);
			marked[1] = (B <= 127);
			marked[2] = (C <= 127);
			marked[3] = (D <= 127);
			marked[4] = (E <= 127);

			if (static_cast<int>(count(begin(marked), end(marked), true)) == 1) {
				if (marked[0]) {
					cout << 'A' << '\n';
				}
				else if (marked[1]) {
					cout << 'B' << '\n';
				}
				else if (marked[2]) {
					cout << 'C' << '\n';
				}
				else if (marked[3]) {
					cout << 'D' << '\n';
				}
				else {
					cout << 'E' << '\n';
				}
			}
			else {
				cout << '*' << '\n';
			}
		}
	}
	
	return 0;
}