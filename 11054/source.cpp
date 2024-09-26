#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, maximum = 0;
	cin >> N;

	vector<int> A(N);
	vector<int> increasing(N, 1);
	vector<int> reverseIncreasing(N, 1);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				increasing[i] = max(increasing[i], increasing[j] + 1);
			}
		}
	}
	
	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (A[j] < A[i]) {
				reverseIncreasing[i] = max(reverseIncreasing[i], reverseIncreasing[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		maximum = max(maximum, increasing[i] + reverseIncreasing[i]);
	}

	cout << maximum - 1;

	return 0;
}
