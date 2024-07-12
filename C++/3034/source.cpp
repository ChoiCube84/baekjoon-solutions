#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W, H;
    cin >> N >> W >> H;

    for (int i=0; i<N; i++) {
        int length;
        cin >> length;

        if (W * W + H * H >= length * length) {
            cout << "DA" << '\n';
        }
        else {
            cout << "NE" << '\n';
        }
    }
    
    return 0;
}