#include <bits/extc++.h>
#include "segment_tree.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct MyMonoid {
    int value;
    int index;
    bool identity;

    MyMonoid(int value=1, int index=100000, bool identity=true) : index(index), value(value), identity(identity) {}

    MyMonoid operator*(const MyMonoid& other) const {
        if (this->identity) {
            return other;
        }
        else if (other.identity) {
            return *this;
        }
        else {
            MyMonoid result;

            if (this->value < other.value) {
                result.value = this->value;
                result.index = this->index;
            }
            else if (this->value > other.value) {
                result.value = other.value;
                result.index = other.index;
            }
            else {
                result.value = this->value;
                result.index = min(this->index, other.index);
            }

            result.identity = false;

            return result;
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<MyMonoid> A(N);
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;

        A[i] = MyMonoid(temp, i, false);
    }

    SegmentTree<MyMonoid> segtree(A);
    
    int M;
    cin >> M;

    for (int m=0; m<M; m++) {
        int q, i, j;
        cin >> q >> i >> j;

        if (q == 1) {
            segtree.update(i-1, MyMonoid(j, i-1, false));
        }
        else {
            cout << segtree.query(i-1, j-1).index + 1 << '\n';
        }
    }
    
    return 0;
}