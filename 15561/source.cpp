#include <bits/extc++.h>
#include "segment_tree.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int U, V;

struct MyMonoid {
    int leftMax;
    int rightMax;
    int totalMax;
    int totalSum;

    bool isIdentity;

    MyMonoid(int K=0, bool isIdentity=true) : leftMax(U * K + V), rightMax(U * K + V), totalMax(U * K + V), totalSum(U * K + V), isIdentity(isIdentity) {
        if (K != 0) {
            isIdentity = false;
        }
    }

    MyMonoid operator+(const MyMonoid& other) const {
        if (this->isIdentity) {
            return other;
        }
        else if (other.isIdentity) {
            return *this;
        }
        else {
            MyMonoid result;

            result.leftMax = max(leftMax, totalSum + other.leftMax);
            result.rightMax = max(rightMax + other.totalSum, other.rightMax);
            result.totalMax = max({
                totalMax,
                other.totalMax,
                rightMax + other.leftMax,
                result.leftMax,
                result.rightMax
            });
            result.totalSum = totalSum + other.totalSum;

            result.isIdentity = false;

            return result;
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q >> U >> V;

    vector<MyMonoid> K(N);
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;

        K[i] = MyMonoid(temp, false);
    }

    SegmentTree<MyMonoid> segtree(K);

    for (int q=0; q<Q; q++) {
        int C, A, B;
        cin >> C >> A >> B;

        if (C == 0) {
            cout << segtree.query(A-1, B-1).totalMax - V << '\n';
        }
        else {
            segtree.update(A-1, MyMonoid(B, false));
        }
    }
    
    return 0;
}