#ifndef __SEGMENT_TREE_HPP__
#define __SEGMENT_TREE_HPP__

#include <vector>

using ull = unsigned long long int;

class SegmentTree {
private:
    std::vector<std::pair<ull, ull>> tree;
    std::vector<ull> arr;
    size_t n;

    void build(size_t idx, size_t left, size_t right) {
        if (left == right) {
            tree[idx].first = arr[left];
            tree[idx].second = arr[left];
            return;
        }

        size_t mid = (left + right) / 2;

        build(2 * idx, left, mid);
        build(2 * idx + 1, mid + 1, right);

        const std::pair<ull, ull>& leftValue = tree[2 * idx];
        const std::pair<ull, ull>& rightValue = tree[2 * idx + 1];

        tree[idx].first = std::min(leftValue.first, rightValue.first);
        tree[idx].second = std::max(leftValue.second, rightValue.second);
    }

    const std::pair<ull, ull> query(size_t i, size_t j, size_t node, size_t currentLeft, size_t currentRight) {
        if (j < currentLeft || currentRight < i) {
            return std::make_pair(ULLONG_MAX, 0ULL);
        }
        else if (i <= currentLeft && currentRight <= j) {
            return tree[node];
        }
        else {
            size_t mid = (currentLeft + currentRight) / 2;
            const std::pair<ull, ull> leftValue = query(i, j, 2 * node, currentLeft, mid);
            const std::pair<ull, ull> rightValue = query(i, j, 2 * node + 1, mid + 1, currentRight);

            ull minimum = std::min(leftValue.first, rightValue.first);
            ull maximum = std::max(leftValue.second, rightValue.second);
            
            return std::make_pair(minimum, maximum);
        }
    }

public:
    SegmentTree(const std::vector<ull>& a) : arr(a), n(a.size()) {
        tree.resize(4 * n + 1);
        build(1, 0, n - 1);
    }

    const std::pair<ull, ull> query(size_t i, size_t j) {
        return query(i, j, 1, 0, n - 1);
    }
};

#endif // !__SEGMENT_TREE_HPP__
