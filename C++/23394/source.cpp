#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<priority_queue<int, vector<int>, greater<int>>> blocks(K+1);
    vector<int> colorOrder(N, 0);
    
    for (int i=0; i<N; i++) {
        int n, c;
        cin >> n >> c;
        
        blocks[c].push(n);
        colorOrder[i] = c;
    }
    
    int prev;
    int curr = blocks[colorOrder[0]].top();
    
    blocks[colorOrder[0]].pop();
    
    for (int i=1; i<N; i++) {
        prev = curr;
        curr = blocks[colorOrder[i]].top();
        
        blocks[colorOrder[i]].pop();
        
        if (prev > curr) {
            cout << 'N';
            return 0;
        }
    }
    
    cout << 'Y';
    
    return 0;
}
