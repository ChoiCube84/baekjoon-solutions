#ifndef __SEGMENT_TREE_HPP__
#define __SEGMENT_TREE_HPP__

#include <vector>

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
            if (currentLeft == currentRight) {
                tree[node] = value;
            }
            else {
                size_t mid = (currentLeft + currentRight) / 2;
                
                update(index, value, 2 * node, currentLeft, mid);
                update(index, value, 2 * node + 1, mid + 1, currentRight);
                
                tree[node] = tree[2 * node] + tree[2 * node + 1];
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

#endif // !__SEGMENT_TREE_HPP__
