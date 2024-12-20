#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ld weight;
	
	cout << fixed;
	cout << setprecision(2);
	
	while (true) {
		cin >> weight;
		
		if (weight == -1.0L) {
			break;
		}
		
		cout << "Objects weighing " << weight << " on Earth will weigh " << weight * 0.167L << " on the moon." << '\n';
	}
	
	return 0;
}