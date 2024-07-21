#include <bits/extc++.h>
#include "segment_tree.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

struct Plate {
    int left;
    int right;
    bool penetrable;
    bool identity;

    Plate(int angle=1, bool identity=true) : left(angle), right(angle), penetrable(true), identity(identity) {
        if (angle != 1) {
            identity = false;
        }
    };
    
    Plate operator* (const Plate& other) const {
        Plate result;
        
        if (identity) {
            return other;
        }
        else if (other.identity) {
            return *this;
        }
        else {
            if (penetrable && other.penetrable 
                && (abs(right - other.left) % 8 != 2) 
                && (abs(right - other.left) % 8 != 6)) 
            {
                result.penetrable = true;
            }
            else {
                result.penetrable = false;
            }
            
            result.left = left;
            result.right = other.right;

            result.identity = false;
            
            return result;
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    vector<Plate> A(N);
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;

        A[i] = Plate(temp, false);
    }

    SegmentTree<Plate> segtree(A);

    for (int i=0; i<M; i++) {
        int q, a, b;
        cin >> q >> a >> b;
        
        if (q == 1) {
            segtree.update(a-1, Plate(b, false));
        }
        else {
            cout << segtree.query(a-1, b-1).penetrable << '\n';
        }
    }
    
    return 0;
}