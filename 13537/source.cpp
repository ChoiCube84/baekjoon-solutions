#include <bits/stdc++.h>

using namespace std;

template <typename T>
class MergeSortTree {
private:
    std::vector<std::vector<T>> tree;
    std::vector<T> arr;
    size_t n;

    void build(size_t idx, size_t left, size_t right) {
        if (left == right) {
            tree[idx].resize(1);
            tree[idx][0] = arr[left];
            return;
        }

        size_t mid = (left + right) / 2;

        build(2 * idx, left, mid);
        build(2 * idx + 1, mid + 1, right);

        tree[idx].resize(tree[2 * idx].size() + tree[2 * idx + 1].size());
        std::merge(tree[2 * idx].begin(), tree[2 * idx].end(),
            tree[2 * idx + 1].begin(), tree[2 * idx + 1].end(),
            tree[idx].begin());
    }

    size_t query(size_t i, size_t j, const T& k, size_t node, size_t currentLeft, size_t currentRight) {
        size_t result;

        if (j < currentLeft || currentRight < i) {
            result = 0;
        }
        else if (i <= currentLeft && currentRight <= j) {
            result = tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
        }
        else {
            size_t mid = (currentLeft + currentRight) / 2;
            result = query(i, j, k, 2 * node, currentLeft, mid) + query(i, j, k, 2 * node + 1, mid + 1, currentRight);
        }

        return result;
    }

public:
    MergeSortTree(const std::vector<T>& a) : arr(a), n(a.size()) {
        tree.resize(4 * n + 1);
        build(1, 0, n - 1);
    }

    size_t query(size_t i, size_t j, const T& k) {
        return query(i, j, k, 1, 0, n - 1);
    }
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N;

	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	MergeSortTree<int> mst(a);

	cin >> M;

	for (int query = 0; query < M; query++) {
		int i, j, k;
		cin >> i >> j >> k;

        cout << mst.query(i - 1, j - 1, k) << "\n";
	}

	return 0;
}
