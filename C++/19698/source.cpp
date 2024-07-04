#include <bits/extc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W, H, L;
    cin >> N >> W >> H >> L;

    cout << min(N, (W / L) * (H / L));

    return 0;
}