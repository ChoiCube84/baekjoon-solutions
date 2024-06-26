#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int A, B;
    cin >> A >> B;

    bool flip = false;
    
    for (int i=0; i<M; i++) {
        int K;
        cin >> K;

        if (flip) {
            if (B <= K) {
                flip = !flip;
            }
        }
        else {
            if (A <= K) {
                flip = !flip;
            }
        }
    }

    if (flip) {
        cout << B;
    }
    else {
        cout << A;
    }
    
    return 0;
}