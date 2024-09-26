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
	
	int Z;
	cin >> Z;

	for (int i=0; i<Z; i++) {
		int N, M;
		cin >> N >> M;

		int U, V;
		
		if (N % M == 0) {
			U = N - M;
		} 
		else {
			U = (N / M) * M;
		}
		
		V = U - M;
		
		if (U <= 0 || V <= 0) {
			cout << "Reseni neexistuje." << '\n';
		}
		else {
			cout << U << ' ' << V << "\n";
		}
	}
	
	return 0;
}