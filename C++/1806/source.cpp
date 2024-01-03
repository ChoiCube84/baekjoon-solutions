#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned long long int N, S, sum = 0;
    cin >> N >> S;

    vector<unsigned long long int> arr(N+1);
    for (int i=1; i<=N; i++) {
        unsigned long long int curr;
        cin >> curr;

        sum += curr;
        arr[i] = sum;
    }
    arr[0] = 0;

    int left = 1;
    int right = 1;

    int shortest = INT_MAX;

    while (left <= N && right <= N) {
        if (left > right) {
            right++;
            continue;
        }

        unsigned long long int partSum = arr[right] - arr[left - 1];

        if (partSum < S) {
            right++;
        }
        else {
            shortest = min(shortest, right - left + 1);
            left++;
        }
    }

    if (shortest == INT_MAX) {
        cout << 0;
    }
    else {
        cout << shortest;
    }

    return 0;
}
