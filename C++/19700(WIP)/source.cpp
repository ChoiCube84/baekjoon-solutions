#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct cmp {
	bool operator()(const pll& a, const pll& b) const {
		if (a.first < b.first) {
			return true;
		}
		else if (a.first == b.first && a.second < b.second) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<pll> students(N);

	for (int i=0; i<N; i++) {
		cin >> students[i].first >> students[i].second;
	}

	sort(students.begin(), students.end(), cmp());

	// int groups = 0;

	// while (students.size() > 0) {
	// 	pll tallest = students.back();
	// 	students.pop_back();

	// 	// WIP
	// }

	cout << '\n';
	for (int i=0; i<N; i++) {
		cout << students[i].first << " " << students[i].second << '\n';
	}
	
	return 0;
}