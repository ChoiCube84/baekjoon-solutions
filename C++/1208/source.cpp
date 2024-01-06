#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int getSum(const vector<int>& arr, int bitInfo);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> a, b;
    unordered_map<int, long long int> half;

    int N, S;
    long long int result = 0;

    cin >> N >> S;

    for (int i=0; i<(N/2); i++) {
        int temp;
        cin >> temp;
        a.emplace_back(temp);
    }

    for (int i=(N/2); i<N; i++) {
        int temp;
        cin >> temp;
        b.emplace_back(temp);
    }

    for (int i = 0; i < (1 << (N/2)); i++) {
        int sum = getSum(a, i);
        if (half.find(sum) == half.end()) {
            half[sum] = 1;
        }
        else {
            half[sum]++;
        }
    }

    for (int i = 0; i < (1 << (N-(N/2))); i++) {
        int sum = getSum(b, i);
        result += half[S - sum];
    }

    if (S == 0) {
        result--;
    }

    cout << result;

    return 0;
}

int getSum(const vector<int>& arr, int bitInfo) {
    int result = 0;
    for (int i = 0; bitInfo > 0; i++) {
        if (bitInfo % 2 == 1) {
            result += arr[i];
        }
        bitInfo >>= 1;
    }
    return result;
}
