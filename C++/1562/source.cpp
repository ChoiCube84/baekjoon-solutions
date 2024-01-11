#define MOD 1000000000
#include <bits/stdc++.h>

using namespace std;

int N;
int dp[10][101][1 << 10] = {0,};

int search(int start, int currentDigit, int bits);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int result = 0;

    for (int i=1; i<10; i++) {
        result += search(i, 1, 1 << i);
        result %= MOD;
    }

    cout << result;

    return 0;
}

int search(int start, int currentDigit, int bits) {
    if (start < 0 || start > 9) {
        return 0;
    }
    else if (dp[start][currentDigit][bits] != 0) {
        return dp[start][currentDigit][bits];
    }
    else if (currentDigit == N) {
        if (bits == (1 << 10) - 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        int result=0;

        result += search(start + 1,
                         currentDigit + 1,
                         bits | 1 << (start + 1));

        result %= MOD;

        result += search(start - 1,
                         currentDigit + 1,
                         bits | 1 << (start - 1));

        result %= MOD;

        dp[start][currentDigit][bits] = result;

        return result;
    }
}
