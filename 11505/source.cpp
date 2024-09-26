#include <bits/extc++.h>
#include "segment_tree.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct MyMonoid {
    ull num;

    MyMonoid(ull num=1) : num(num % 1000000007ULL) {}

    MyMonoid operator*(const MyMonoid& other) const {
        return MyMonoid(num * other.num);
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull N, M, K;
    cin >> N >> M >> K;

    vector<MyMonoid> arr(N);
    for (ull i=0; i<N; i++) {
        ull temp;
        cin >> temp;

        arr[i] = MyMonoid(temp);
    }

    SegmentTree<MyMonoid> segtree(arr);

    for (ull i=0; i<M+K; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            segtree.update(b-1, MyMonoid(c));
        }
        else {
            cout << segtree.query(b-1, c-1).num << '\n';
        }
    }
    
    return 0;
}