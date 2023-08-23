#include <bits/stdc++.h>

using namespace std;

bool dp[2001][2001] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N;

	vector<int> arr(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i][i] = true;
		if (i < N) {
			if (arr[i] == arr[i + 1]) {
				dp[i][i + 1] = true;
			}
		}
	}

	for (int interval = 2; interval <= N - 1; interval++) {
		for (int i = 1; i <= N - interval; i++) {
			int j = i + interval;
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == true) {
				dp[i][j] = true;
			}
		}
	}

	cin >> M;

	for (int query = 0; query < M; query++) {
		int start, end;
		cin >> start >> end;

		if (dp[start][end] == true) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}
