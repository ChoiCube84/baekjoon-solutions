#include <bits/stdc++.h>
#include "segment_tree.hpp"

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    SegmentTree<long long int> segTree(arr);

    for (int i = 0; i < M + K; i++) {
        long long int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            segTree.update(b - 1, c);
        }
        else if (a == 2) {
            cout << segTree.query(b - 1, c - 1) << "\n";
        }
    }

	return 0;
}
