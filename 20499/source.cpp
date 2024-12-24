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
	
	string input;
	cin >> input;
	
	ll K, D, A;
	char temp;
	
	stringstream ss(input);
	
	ss >> K >> temp >> D >> temp >> A;
	
	if (K + A < D || D == 0) {
		cout << "hasu";
	}
	else {
		cout << "gosu";
	}	
	
	return 0;
}