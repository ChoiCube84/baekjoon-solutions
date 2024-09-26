#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int K = 1;
    vector<int> color(N+1, 1);
    
    for (int i=2; i<=N; i++) {
        if (color[i] == 1) {
            K++;
            for (int j=i; j<=N; j+=i) {
                color[j] = K;
            }
        }
    }

    cout << K << "\n";
    for (int i=1; i<=N; i++) {
        cout << color[i] << " ";
    }
    
    return 0;
}