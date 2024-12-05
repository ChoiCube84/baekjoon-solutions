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
	
	queue<ll> q;
	
	while (true) {
		ll data;
		cin >> data;
		
		if (data == -1) {
			break;
		}	
		else if (data == 0) {
			q.pop();
		}
		else if (q.size() < N) {
			q.push(data);
		}
	}
	
	if (q.empty()) {
		cout << "empty";
	}
	else {
		while (!q.empty()) {
			ll curr = q.front();
			cout << curr << ' ';
			
			q.pop();
		}
	}
	
	return 0;
}