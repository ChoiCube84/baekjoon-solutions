#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long int;

ull lcm(ull a, ull b);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ull K, N;
    cin >> K >> N;
    
    ull result = 1;
    
    for (ull i=0; i<N; i++) {
        ull A;
        cin >> A;
        
        result = lcm(result, A);
    }
    
    cout << result - K;
    
    return 0;
}

ull lcm(ull a, ull b) {
    return a * b / gcd(a, b);
}
