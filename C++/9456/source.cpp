#include <bits/stdc++.h>

using namespace std;

int dp[3][100001] = { 0, };
int value[2][100001] = { 0, };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> value[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			dp[0][i] = max({ dp[0][i - 1], dp[1][i - 1], dp[2][i - 1] }); // No sticker
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + value[0][i]; // Up sticker
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + value[1][i]; // Down sticker
		}

		cout << max({ dp[0][n], dp[1][n], dp[2][n] }) << "\n";
	}

	return 0;
}
