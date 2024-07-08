#include <bits/extc++.h>
#include "segment_tree.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<ull> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    SegmentTree tree(A);

    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;
        
        pll answer = tree.query(a, b);
        cout << answer.first << ' ' << answer.second << '\n';
    }
    
    return 0;
}