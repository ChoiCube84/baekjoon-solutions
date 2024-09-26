#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    int M;
    cin >> M;
    
    vector<int> B(M);
    for (int i=0; i<M; i++) {
        cin >> B[i];
    }
    
    vector<int> result;
    
    int startA = 0;
    int startB = 0;
    
    for (int target=100; target>0; target--) {
        for (int i=startA; i<N; i++) {
            if (A[i] == target) {
                for (int j=startB; j<M; j++) {
                    if (B[j] == target) {
                        result.emplace_back(target);
                        
                        startA = i+1;
                        startB = j+1;
                        
                        break;
                    }
                }
            }
        }
    }
    
    cout << result.size() << "\n";
    for (auto& i : result) {
        cout << i << " ";
    }
    
    return 0;
}
