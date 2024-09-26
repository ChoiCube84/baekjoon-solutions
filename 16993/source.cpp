#include <bits/stdc++.h>

using namespace std;

struct Node {
    int maxSum;
    int prefixSum;
    int suffixSum;
    int totalSum;
};

class SegmentTree {
private:
    std::vector<Node> tree;
    std::vector<int> arr;
    int n;

    void build(int idx, int left, int right) {
        if (left == right) {
            tree[idx] = { arr[left], arr[left], arr[left], arr[left] };
            return;
        }
        int mid = (left + right) / 2;
        build(2 * idx, left, mid);
        build(2 * idx + 1, mid + 1, right);

        const Node& leftNode = tree[2 * idx];
        const Node& rightNode = tree[2 * idx + 1];

        tree[idx].maxSum = std::max({ leftNode.maxSum, rightNode.maxSum, leftNode.suffixSum + rightNode.prefixSum });
        tree[idx].totalSum = leftNode.totalSum + rightNode.totalSum;
        tree[idx].prefixSum = std::max(leftNode.prefixSum, leftNode.totalSum + rightNode.prefixSum);
        tree[idx].suffixSum = std::max(rightNode.suffixSum, rightNode.totalSum + leftNode.suffixSum);
    }

    Node merge(const Node& left, const Node& right) {
        if (left.maxSum == INT_MIN) {
            return right;
        }
        else if (right.maxSum == INT_MIN) {
            return left;
        }
        else {
            Node result;

            result.maxSum = std::max({ left.maxSum, right.maxSum, left.suffixSum + right.prefixSum });
            result.totalSum = left.totalSum + right.totalSum;
            result.prefixSum = std::max(left.prefixSum, left.totalSum + right.prefixSum);
            result.suffixSum = std::max(right.suffixSum, right.totalSum + left.suffixSum);

            return result;
        }
    }

    Node query(int i, int j, int node, int currentLeft, int currentRight) {
        if (j < currentLeft || currentRight < i) {
            return { INT_MIN, INT_MIN, INT_MIN, INT_MIN };
        }
        else if (i <= currentLeft && currentRight <= j) {
            return tree[node];
        }
        else {
            int mid = (currentLeft + currentRight) / 2;
            Node left = query(i, j, 2 * node, currentLeft, mid);
            Node right = query(i, j, 2 * node + 1, mid + 1, currentRight);

            return merge(left, right);
        }
    }

public:
    SegmentTree(const std::vector<int>& a) : arr(a), n(a.size()) {
        tree.resize(4 * n + 1);
        build(1, 0, n - 1);
    }

    int query(int i, int j) {
        if (i == j) {
            return arr[i];
        }
        else {
            return query(i, j, 1, 0, n - 1).maxSum;
        }
    }
};

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

	SegmentTree segTree(A);

	cin >> M;
	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		cout << segTree.query(i - 1, j - 1) << "\n";
	}

	return 0;
}