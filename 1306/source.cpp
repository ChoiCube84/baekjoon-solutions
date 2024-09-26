#include <bits/stdc++.h>
#include "segment_tree.hpp"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> intensity(N);
    
    for (int i=0; i<N; i++) {
        cin >> intensity[i];
    }
    
    SegmentTree<int> segtree(intensity);
    
    for (int i=M-1; i<N-M+1; i++) {
        cout << segtree.query(i - (M-1), i + (M-1)) << " ";
    }
    
    return 0;
}
