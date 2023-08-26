#include <bits/stdc++.h>

using namespace std;

vector<int> arr(1000000);
vector<int> indexOfLIS(1000000);
vector<int> dp;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, length;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		
		if (i == 0 || arr[i] > dp.back()) {
			dp.emplace_back(arr[i]);
			indexOfLIS[i] = dp.size() - 1;
		}
		else {
			int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
			dp[index] = arr[i];
			indexOfLIS[i] = index;
		}
	}

	length = dp.size();
	cout << length << "\n";

	stack<int> s;
	int currentIndex = length - 1;

	for (int i = N - 1; currentIndex >= 0; i--) {
		if (indexOfLIS[i] == currentIndex) {
			s.push(arr[i]);
			currentIndex--;
		}
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}
