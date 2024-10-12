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
	
	ll N, count[4] = {0,};
	cin >> N;
	
	for (ll i=0; i<N; i++) {
		ll value;
		cin >> value;
		
		count[value]++;
	}
	
	ll total = 0;
	
	ll pair_0_3 = min(count[0], count[3]);
	total += 3 * pair_0_3;
	count[0] -= pair_0_3;
	count[3] -= pair_0_3;
	
	ll pair_1_2 = min(count[1], count[2]);
	total += 3 * pair_1_2;
	count[1] -= pair_1_2;
	count[2] -= pair_1_2;
	
	ll pair_1_3 = min(count[1], count[3]);
	total += 2 * pair_1_3;
	count[1] -= pair_1_3;
	count[3] -= pair_1_3;
	
	ll pair_0_2 = min(count[0], count[2]);
	total += 2 * pair_0_2;
	count[0] -= pair_0_2;
	count[2] -= pair_0_2;
	
	ll pair_2_3 = min(count[2], count[3]);
	total += pair_2_3;
	count[2] -= pair_2_3;
	count[3] -= pair_2_3;
	
	ll pair_0_1 = min(count[0], count[1]);
	total += pair_0_1;
	count[0] -= pair_0_1;
	count[1] -= pair_0_1;
	
	cout << total;
	
	return 0;
}