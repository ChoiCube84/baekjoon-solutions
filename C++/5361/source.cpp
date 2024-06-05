#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    for (int i=0; i<T; i++) {
        int A, B, C, D, E;
        cin >> A >> B >> C >> D >> E;
        
        long long int sum = A * 35034 + B * 23090 + C * 19055 + D * 12530 + E * 18090;
        
        cout << "$" << sum / 100 << ".";
        
        if (sum % 100 < 10) {
            cout << "0";
        }
        
        cout << sum % 100 << "\n";
    }
    
    return 0;
}
