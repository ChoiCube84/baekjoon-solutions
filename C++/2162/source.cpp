#include <bits/stdc++.h>
#include "geometric_line.hpp"
#include "disjoint_set.hpp"

using namespace std;

using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<GeometricLine<ll>> lines(N);
    DisjointSet diset(N);
    vector<int> lineCount(N, 0);

    for (int i=0; i<N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        lines[i].update({x1, y1}, {x2, y2});
    }

    for (int i=0; i<N; i++) {
        GeometricLine<ll>& curr = lines[i];

        for (int j=0; j<N; j++) {
            GeometricLine<ll>& next = lines[j];

            if (diset.find(i) != diset.find(j) && curr.cross(next)) {
                diset.merge(i, j);
            }
        }
    }

    int groups = 0;
    int maximum = INT_MIN;
    for (int i=0; i<N; i++) {
        int curr = diset.find(i);

        if (lineCount[curr] == 0) {
            groups++;
        }

        lineCount[curr]++;
        maximum = max(maximum, lineCount[curr]);
    }

    cout << groups << "\n" << maximum;

    return 0;
}
