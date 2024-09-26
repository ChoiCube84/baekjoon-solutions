#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long int;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ull N;
    cin >> N;
    
    vector<pair<ull, ull>> matrices(N);
        
    for (int i=0; i<N; i++) {
        cin >> matrices[i].first >> matrices[i].second;
    }
    
    ull result = 0;
    ull finalColumn = matrices[N-1].second;
    
    for (int i=N-2; i>=0; i--) {
        result += (matrices[i].first * matrices[i].second * finalColumn);
    }
    
    cout << result;
    
    return 0;
}
