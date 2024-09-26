#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, M;
    cin >> H >> M;

    cout << H * 60 + M;
    
    return 0;
}