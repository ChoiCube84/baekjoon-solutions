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
	
	string courses;
	
	for (ll i=0; i<N; i++) {
		char c;
		cin >> c;
		
		courses += c;
	}
	
	char my_course;
	cin >> my_course;
	
	ll result = 0;
	
	for (auto& c : courses) {
		if (c == my_course) {
			result++;
		}
	}
	
	cout << result;
	
	return 0;
}