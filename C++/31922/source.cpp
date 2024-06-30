#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, P, C;
    cin >> A >> P >> C;

    cout << max(A + C, P);

    return 0;
}