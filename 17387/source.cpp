#include <bits/stdc++.h>
#include "geometric_line.hpp"

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<double, double> p1, p2, p3, p4;

    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;

    GeometricLine<double> L1(p1, p2);
    GeometricLine<double> L2(p3, p4);

    if (L1.cross(L2)) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
