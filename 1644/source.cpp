#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const ull inputRange = 4000000ULL;
    vector<bool> isPrime(inputRange + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (ull curr=2; curr<=inputRange; curr++) {
        if (isPrime[curr]) {
            for (ull multiple=curr*curr; multiple<=inputRange; multiple+=curr) {
                isPrime[multiple] = false;
            }
        }
    }

    int N;
    cin >> N;

    vector<int> prefixSum;

    int sum = 0;
    prefixSum.emplace_back(0);

    for (int i=2; i<=inputRange; i++) {
        if (isPrime[i]) {
            sum += i;
            prefixSum.emplace_back(sum);
        }
    }

    int start = 0;
    int end = 1;

    int result = 0;

    while (start < end && start < prefixSum.size() && end < prefixSum.size()) {
        int curr = prefixSum[end] - prefixSum[start];

        if (curr < N) {
            end++;
        }
        else if (curr > N) {
            start++;
        }
        else {
            result++;
            start++;
            end++;
        }
    }

    cout << result;

    return 0;
}
