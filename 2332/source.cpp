#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string number;
    cin >> number;

    int n;
    cin >> n;

    gp_hash_table<string, string> table;

    for (int i=0; i<n; i++) {
        string word, converted;
        cin >> word;

        for (char c : word) {
            switch (c) {
                case 'i':
                case 'j':
                    converted += '1';
                    break;

                case 'a':
                case 'b':
                case 'c':
                    converted += '2';
                    break;

                case 'd':
                case 'e':
                case 'f':
                    converted += '3';
                    break;

                case 'g':
                case 'h':
                    converted += '4';
                    break;

                case 'k':
                case 'l':
                    converted += '5';
                    break;

                case 'm':
                case 'n':
                    converted += '6';
                    break;

                case 'p':
                case 'r':
                case 's':
                    converted += '7';
                    break;

                case 't':
                case 'u':
                case 'v':
                    converted += '8';
                    break;

                case 'w':
                case 'x':
                case 'y':
                    converted += '9';
                    break;

                case 'o':
                case 'q':
                case 'z':
                    converted += '0';
                    break;
            }
        }

        table[converted] = word;
    }

    vector<pll> dp(number.size(), {INT_MAX, -1}); // First is number of words, second is previous index

    for (int i=1; i<=number.size(); i++) {
        for (int j=0; j<i; j++) {
            if (j == 0) {
                if (table.find(number.substr(0, i)) != table.end()) {
                    dp[i-1] = {1, -1};
                    break;
                }
            }
            else if (dp[j-1].first != 0) {
                if (table.find(number.substr(j, i-j)) != table.end()) {
                    if (dp[i-1].first > dp[j-1].first+1) {
                        dp[i-1].first = dp[j-1].first+1;
                        dp[i-1].second = j-1;
                    }
                }
            }
        }
    }

    vector<string> wordList;

    int prev = dp[number.size()-1].second;
    int curr = number.size()-1;

    while (true) {
        if (dp[number.size()-1].first != INT_MAX) {
            wordList.emplace_back(table[number.substr(prev+1, curr-prev)]);
        }

        if (prev == -1) {
            break;
        }
        else {
            curr = prev;
            prev = dp[prev].second;
        }
    }

    reverse(wordList.begin(), wordList.end());

    cout << wordList.size() << '\n';

    if (wordList.size() == 0) {
        cout << "No solution.";
    }
    else {
        for (string word : wordList) {
            cout << word << '\n';
        }
    }

    return 0;
}