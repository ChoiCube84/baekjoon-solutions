#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        int H, M;
        cin >> H >> M;

        M -= 45;
        if (M < 0) {
            M += 60;
            H--;
        }
        if (H < 0) {
            H += 24;
        }

        cout << "Case #" << t << ": " << H << " " << M << "\n";
    }
    
    return 0;
}