#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> c(n);
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }
    
    sort(c.begin(), c.end());
    
    long double maximumFraction = 1;
    
    for (int i=0; i<n; i++) {
        if (i+1 < c[i]) {
            cout << "impossible";
            return 0;
        }
        else {
            maximumFraction = min(maximumFraction, static_cast<long double>(c[i]) / (i+1));
        }
    }
    
    cout << maximumFraction;
    
    return 0;
}
