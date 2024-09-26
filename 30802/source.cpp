#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    vector<int> sizes(6);
    for (int i=0; i<6; i++) {
        cin >> sizes[i];   
    }
    
    int T, P;
    cin >> T >> P;
    
    int sum = 0;
    for (int i=0; i<6; i++) {
        sum += (sizes[i] / T + 1);
        
        if (sizes[i] % T == 0) {
            sum--;
        }
    }
    
    cout << sum << "\n" << (N / P) << " " << (N % P);
    
    return 0;
}
