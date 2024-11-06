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
	
	ll n, d, k;
	cin >> n >> d >> k;
	
	vector<pair<ll, string>> employees;
	
	for (ll i=0; i<n; i++) {
		string s;
		ll c;
		
		cin >> s >> c;
		
		employees.emplace_back(make_pair(c, s));
	}
	
	sort(employees.rbegin(), employees.rend());
	
	ll fire_count, salary_sum = 0;
	for (fire_count=0; fire_count<k; fire_count++) {
		if (salary_sum >= d) {
			break;
		}
		salary_sum += employees[fire_count].first;
	}
	
	if (salary_sum < d) {
		cout << "impossible";
	}
	else {
		cout << fire_count << '\n';
		for (ll i=0; i<fire_count; i++) {
			cout << employees[i].second << ", YOU ARE FIRED!" << '\n';
		}
	}
	
	return 0;
}