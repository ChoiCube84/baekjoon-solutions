#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    int Q;
    cin >> Q;

    for (int q=0; q<Q; q++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        vector<int> X(26, 0);
        vector<int> Y(26, 0);

        for (int i=A; i<=B; i++) {
            X[S[i] - 'a']++;
        }

        for (int i=C; i<=D; i++) {
            Y[S[i] - 'a']++;
        }

        bool success = true;
        
        for (int i=0; i<26; i++) {
            if (X[i] != Y[i]) {
                success = false;
                cout << "NE" << "\n";
                break;
            }
        }

        if (success) {
            cout << "DA" << "\n";
        }
    }
    
    return 0;
}