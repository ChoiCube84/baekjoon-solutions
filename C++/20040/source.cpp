#include <bits/stdc++.h>
#include "disjoint_set.hpp"

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DisjointSet diset(n);
    bool success = false;

    for (int i=1; i<=m; i++) {
        int A, B;
        cin >> A >> B;

        if (diset.find(A) == diset.find(B)) {
            success = true;
            cout << i;
            break;
        }
        else {
            diset.merge(A, B);
        }
    }

    if (!success) {
        cout << 0;
    }

    return 0;
}
