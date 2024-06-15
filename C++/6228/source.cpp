#include <bits/stdc++.h>

using namespace std;

vector<int> getCombination(int i, int S, int N);
vector<int> extractCounts(const vector<int>& combination, int S);
bool conditionCheck(const vector<int>& counts, int W, int R);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, S, E, result = 0;
    cin >> N >> S >> E;
    
    vector<string> conditions(E);
    
    for (int i=0; i<E; i++) {
        cin >> conditions[i];
    }
    
    for (int i=0; i<pow(S, N); i++) {
        vector<int> combination = getCombination(i, S, N);
        vector<int> counts = extractCounts(combination, S);
        
        bool success = false;
        
        for (auto& condition : conditions) {
            if (success) {
                break;
            }
            else {
                success = true;
            }
            
            for (int i=0; i<condition.length(); i++) {
                if (condition[i] >= '0' && condition[i] <= '9') {
                    int W = condition[i] - '0';
                    i++;
                    
                    if (condition[i] >= '0' && condition[i] <= '9') {
                        W = W * 10 + (condition[i] - '0');
                        i++;
                    }
                    
                    i++;
                    
                    int R = condition[i] - '0';
                    i++;
                    
                    if (condition[i] >= '0' && condition[i] <= '9') {
                        R = R * 10 + (condition[i] - '0');
                        i++;
                    }
                    
                    success = conditionCheck(counts, W, R);
                }
                
                if (success == false) {
                    break;
                }
            }
        }
        
        if (success) {
            result++;
        }
    }
    
    cout << result;
    
    return 0;
}

vector<int> getCombination(int i, int S, int N) {
    vector<int> result;
    
    while (i > 0) {
        result.emplace_back((i % S) + 1);
        i /= S;
    }
    
    while (result.size() < N) {
        result.emplace_back(1);
    }
    
    return result;
}

vector<int> extractCounts(const vector<int>& combination, int S) {
    vector<int> result(S, 0);
    
    for (auto& num : combination) {
        result[num-1]++;
    }
    
    return result;
}

bool conditionCheck(const vector<int>& counts, int W, int R) {
    return (counts[R-1] >= W);
}
