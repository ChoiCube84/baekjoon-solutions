#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int maximum = INT_MIN;
    vector<int> cards(N, 0);
    unordered_set<int> cardCheck;

    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;

        maximum = max(maximum, temp);
        cards[i] = temp;
        cardCheck.insert(temp);
    }

    vector<int> numbers(maximum + 1, 0);

    for (auto& card : cards) {
        for (int i=card*2; i<=maximum; i+=card) {
            if (cardCheck.find(i) != cardCheck.end()) {
                numbers[i]--;
                numbers[card]++;
            }
        }
    }

    for (auto& card : cards) {
        cout << numbers[card] << " ";
    }

    return 0;
}
