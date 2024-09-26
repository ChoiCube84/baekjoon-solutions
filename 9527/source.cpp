#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

vector<ull> totalSetBitsUpTo2PowerN(55, 0);

ull getTotalSetBitsUpToN(ull n);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    totalSetBitsUpTo2PowerN[0] = 0;
    for (int i=1; i<55; i++) {
        totalSetBitsUpTo2PowerN[i]
            = 2 * totalSetBitsUpTo2PowerN[i - 1] + (1ULL << (i - 1));
    }

    ull A, B;
    cin >> A >> B;

    cout << getTotalSetBitsUpToN(B) - getTotalSetBitsUpToN(A - 1);

    return 0;
}

ull getTotalSetBitsUpToN(ull n) {
    ull result = 0;
    int digitCount = 0;

    if (n == 0ULL || n == 1ULL) {
        return n;
    }
    else {
        while (n >= (1ULL << digitCount)) {
            digitCount++;
        }

        result += totalSetBitsUpTo2PowerN[digitCount - 1];

        n ^= (1ULL << (digitCount - 1));
        result += n+1;

        result += getTotalSetBitsUpToN(n);

        return result;
    }
}
