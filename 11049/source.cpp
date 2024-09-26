#include <bits/stdc++.h>

using namespace std;

int dp[501][501] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<pair<int, int>> matrixSize(501);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> matrixSize[i].first >> matrixSize[i].second;
	}

	for (int interval = 1; interval < N; interval++) {
		for (int i = 1; i <= N - interval; i++) {
			int minimum = INT_MAX;

			for (int k = i; k < i + interval; k++) {
				minimum = min(minimum, dp[i][k] + dp[k + 1][i + interval] + matrixSize[i].first * matrixSize[k].second * matrixSize[i + interval].second);
			}

			dp[i][i + interval] = minimum;
		}
	}

	cout << dp[1][N];

	return 0;
}
