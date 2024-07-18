#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

bool isInMiddle(int left, int middle, int right);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, l, M, L, tm, tl;
    cin >> m >> l >> M >> L >> tm >> tl;

    int mToM = abs(m - 0) + abs(M - m);
    int lToL = abs(l - 0) + abs(L - l);

    pll m_first, l_first;

    m_first.first = mToM;
    if (isInMiddle(l, m, L)) {
        m_first.second = mToM + abs(m - M) + abs(L - m);
    }
    else {
        m_first.second = mToM + abs(l - M) + abs(L - l);
    }

    l_first.first = lToL;
    if (isInMiddle(m, l, M)) {
        l_first.second = lToL + abs(l - L) + abs(M - l);
    }
    else {
        l_first.second = lToL + abs(m - L) + abs(M - m);
    }

    if ((m_first.first <= tm && m_first.second <= tl) || (l_first.first <= tl && l_first.second <= tm)) {
        cout << "possible";
    }
    else {
        cout << "impossible";
    }

    return 0;
}

bool isInMiddle(int left, int middle, int right) {
    if (left > right) {
        swap(left, right);
    }

    if (left <= middle && middle <= right) {
        return true;
    }
    else {
        return false;
    }
}