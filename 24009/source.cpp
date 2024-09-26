#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long int;

ull power(ull base, ull exponent, ull divider);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        ull A, N, P, result;
        cin >> A >> N >> P;
        
        result = A;
        
        for (int i=1; i<=N; i++) {
            result = power(result, i, P);
        }
        
        cout << "Case #" << t << ": " << result << "\n";
    }
    
    return 0;
}

ull power(ull base, ull exponent, ull divider) {
    if (exponent == 0) {
        return 1ULL;
    }
    else if (exponent == 1) {
        return base % divider;
    }
    else {
        ull half = power(base, exponent / 2, divider);
        ull result = (half * half) % divider;
        
        if (exponent % 2 == 1) {
            result = (result * base) % divider;
        }
        
        return result;
    }
}
