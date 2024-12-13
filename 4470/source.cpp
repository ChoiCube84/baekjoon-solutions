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
	
	ll N;
	cin >> N;
	
	cin.ignore();
	
	string input;
	
	for (ll i=1; i<=N; i++) {
		getline(cin, input);
		cout << i << ". " << input << '\n';
	}
	
	return 0;
}