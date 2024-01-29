#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    cin >> input;

    ull len = input.length();

    vector<vector<bool>> checkPalindrome(len, vector<bool>(len, false));
    vector<int> dp(len, INT_MAX);

    for (int i=0; i<len; i++) {
        checkPalindrome[i][i] = true;
    }
    for (int i=0; i<len-1; i++) {
        if (input[i] == input[i+1]) {
            checkPalindrome[i][i+1] = true;
        }
    }
    for (int subLen=3; subLen<=len; subLen++) {
        for (int i=0; i<len-subLen+1; i++) {
            if (input[i] == input[i+subLen-1] && checkPalindrome[i+1][i+subLen-2]) {
                checkPalindrome[i][i+subLen-1] = true;
            }
        }
    }

    dp[0] = 1;
    for (int end=1; end<len; end++) {
        for (int begin=0; begin<=end; begin++) {
            if (checkPalindrome[begin][end]) {
                if (begin == 0) {
                    dp[end] = 1;
                }
                else {
                    dp[end] = min(dp[end], dp[begin-1] + 1);
                }
            }
        }
    }

    cout << dp[len - 1];

    return 0;
}
