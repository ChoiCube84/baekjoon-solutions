#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        string S;
        cin >> S;

        vector<int> alphabetCount(26, 0);
        vector<int> result;

        for (auto& c : S) {
            alphabetCount[c - 'A']++;
        }

        for (;alphabetCount['Z' - 'A']>0; alphabetCount['Z' - 'A']--) {
            result.emplace_back(0);
            alphabetCount['E' - 'A']--;
            alphabetCount['R' - 'A']--;
            alphabetCount['O' - 'A']--;
        }

        for (;alphabetCount['W' - 'A']>0; alphabetCount['W' - 'A']--) {
            alphabetCount['T' - 'A']--;
            result.emplace_back(2);
            alphabetCount['O' - 'A']--;
        }

        for (;alphabetCount['U' - 'A']>0; alphabetCount['U' - 'A']--) {
            alphabetCount['F' - 'A']--;
            alphabetCount['O' - 'A']--;
            result.emplace_back(4);
            alphabetCount['R' - 'A']--;
        }

        for (;alphabetCount['X' - 'A']>0; alphabetCount['X' - 'A']--) {
            alphabetCount['S' - 'A']--;
            alphabetCount['I' - 'A']--;
            result.emplace_back(6);
        }

        for (;alphabetCount['G' - 'A']>0; alphabetCount['G' - 'A']--) {
            alphabetCount['E' - 'A']--;
            alphabetCount['I' - 'A']--;
            result.emplace_back(8);
            alphabetCount['H' - 'A']--;
            alphabetCount['T' - 'A']--;
        }

        for (;alphabetCount['H' - 'A']>0; alphabetCount['H' - 'A']--) {
            alphabetCount['T' - 'A']--;
            result.emplace_back(3);
            alphabetCount['R' - 'A']--;
            alphabetCount['E' - 'A']--;
            alphabetCount['E' - 'A']--;
        }

        for (;alphabetCount['F' - 'A']>0; alphabetCount['F' - 'A']--) {
            result.emplace_back(5);
            alphabetCount['I' - 'A']--;
            alphabetCount['V' - 'A']--;
            alphabetCount['E' - 'A']--;
        }

        for (;alphabetCount['V' - 'A']>0; alphabetCount['V' - 'A']--) {
            alphabetCount['S' - 'A']--;
            alphabetCount['E' - 'A']--;
            result.emplace_back(7);
            alphabetCount['E' - 'A']--;
            alphabetCount['N' - 'A']--;
        }

        for (;alphabetCount['O' - 'A']>0; alphabetCount['O' - 'A']--) {
            result.emplace_back(1);
            alphabetCount['N' - 'A']--;
            alphabetCount['E' - 'A']--;
        }

        for (;alphabetCount['T' - 'A']>0; alphabetCount['T' - 'A']--) {
            result.emplace_back(10);
            alphabetCount['E' - 'A']--;
            alphabetCount['N' - 'A']--;
        }

        for (;alphabetCount['I' - 'A']>0; alphabetCount['I' - 'A']--) {
            alphabetCount['N' - 'A']--;
            result.emplace_back(9);
            alphabetCount['N' - 'A']--;
            alphabetCount['E' - 'A']--;
        }

        sort(result.begin(), result.end());

        cout << "Case #" << t << ": ";
        for (auto& i : result) {
            cout << i;
        }
        cout << "\n";
    }

    return 0;
}
