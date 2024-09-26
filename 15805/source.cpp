#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, curr, prev = -1;
    int K = 0;
    
    vector<int> parent(200000, -1);
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        cin >> curr;
        K = max(K, curr + 1);
        
        if (prev == -1) {
            parent[curr] = -1;
        }
        else if (curr != parent[prev]) {
            parent[curr] = prev;
        }
        
        prev = curr;
    }
    
    cout << K << "\n";
    for (int i=0; i<K; i++) {
        cout << parent[i] << " ";
    }
    
    return 0;
}
