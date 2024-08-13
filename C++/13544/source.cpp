#include <bits/stdc++.h>
#include "merge_sort_tree.hpp"

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	MergeSortTree<int> mst(A);
	int last_ans = 0;

	cin >> M;

	for (int query = 0; query < M; query++) {
		int a, b, c;
		cin >> a >> b >> c;

		int i = a ^ last_ans;
		int j = b ^ last_ans;
		int k = c ^ last_ans;

		last_ans = mst.query(i - 1, j - 1, k);

		cout << last_ans << "\n";
	}

	return 0;
}