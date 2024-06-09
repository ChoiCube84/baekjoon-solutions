#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> S(N);
    
    for (int i=0; i<N; i++) {
        cin >> S[i];
        S[i]--;
    }
    
    int result = 1;
    
    int start = 0;
    int end = 0;
    
    int fruitUsed[9] = {0,};
    fruitUsed[S[start]] = 1;
    
    int fruitKindsCount = 1;
    
    while (end < N - 1) {
        end++;
        fruitUsed[S[end]]++;
        
        if (fruitUsed[S[end]] == 1) {
            fruitKindsCount++;
            
            if (fruitKindsCount > 2) {
                do {
                    fruitUsed[S[start]]--;
                    start++;
                } while (fruitUsed[S[start - 1]] > 0);
                
                fruitKindsCount--;
            }
        }
        
        result = max(result, end - start + 1);
    }
    
    cout << result;
    
    return 0;
}
