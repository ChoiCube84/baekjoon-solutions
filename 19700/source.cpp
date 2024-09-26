#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct cmp {
	bool operator()(const pll& a, const pll& b) const {
		if (a.first > b.first) {
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

	multiset<int> groups;

	for (auto& student : students) {
		auto it = groups.lower_bound(student.second);

		if (it == groups.begin()) {
			groups.insert(1);
		}
		else {
			it = prev(it);
			int groupSize = *it;

			groups.erase(it);
			groups.insert(groupSize + 1);
		}
	}

	cout << groups.size();

	return 0;
}