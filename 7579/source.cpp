#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> knapsack(10001, 0);

    vector<int> memory(101, 0);
    vector<int> cost(101, 0);

    for (int i=1; i<=N; i++) {
        cin >> memory[i];
    }

    for (int i=1; i<=N; i++) {
        cin >> cost[i];
    }

    for (int i=1; i<=N; i++) {
        for(int j=10000; j >= cost[i]; j--){
            knapsack[j] = max(knapsack[j], knapsack[j - cost[i]] + memory[i]);
        }
    }

    for (int i=0; i<=10000; i++) {
        if (knapsack[i] >= M) {
            cout << i;
            break;
        }
    }

    return 0;
}
