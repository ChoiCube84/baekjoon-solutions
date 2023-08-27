#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
private:
    std::vector<T> tree;
    std::vector<T> arr;
    size_t n;

    void build(size_t idx, size_t left, size_t right) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }

        size_t mid = (left + right) / 2;

        build(2 * idx, left, mid);
        build(2 * idx + 1, mid + 1, right);

        const T& leftValue = tree[2 * idx];
        const T& rightValue = tree[2 * idx + 1];

        tree[idx] = leftValue + rightValue;
    }

    void update(size_t index, const T& value, size_t node, size_t currentLeft, size_t currentRight) {
        if (currentLeft <= index && index <= currentRight) {
            T difference = value - arr[index];
            tree[node] += difference;

            if (currentLeft != currentRight) {
                size_t mid = (currentLeft + currentRight) / 2;
                update(index, value, 2 * node, currentLeft, mid);
                update(index, value, 2 * node + 1, mid + 1, currentRight);
            }
        }
    }

    const T query(size_t i, size_t j, size_t node, size_t currentLeft, size_t currentRight) {
        if (j < currentLeft || currentRight < i) {
            return 0;
        }
        else if (i <= currentLeft && currentRight <= j) {
            return tree[node];
        }
        else {
            size_t mid = (currentLeft + currentRight) / 2;
            const T leftValue = query(i, j, 2 * node, currentLeft, mid);
            const T rightValue = query(i, j, 2 * node + 1, mid + 1, currentRight);

            return leftValue + rightValue;
        }
    }

public:
    SegmentTree(const std::vector<T>& a) : arr(a), n(a.size()) {
        tree.resize(4 * n + 1);
        build(1, 0, n - 1);
    }

    void update(size_t index, const T& value) {
        update(index, value, 1, 0, n - 1);
        arr[index] = value;
    }

    const T query(size_t i, size_t j) {
        return query(i, j, 1, 0, n - 1);
    }
};

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
