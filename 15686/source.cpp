#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int getDigits(int k);

int getTotalDistance(int k);
int getOneDistance(int k, pair<int, int> house);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int info;
            cin >> info;

            if (info == 1) {
                houses.emplace_back(i, j);
            }
            else if (info == 2) {
                chickens.emplace_back(i, j);
            }
        }
    }

    int minimum = INT_MAX;

    for (int k=1; k < (1 << chickens.size()); k++) {
        if (getDigits(k) > M) {
            continue;
        }

        int temp = getTotalDistance(k);
        minimum = min(minimum, temp);
    }

    cout << minimum;

    return 0;
}

int getDigits(int k) {
    int result = 0;

    while (k > 0) {
        result += (k % 2);
        k >>= 1;
    }

    return result;
}

int getTotalDistance(int k) {
    int total = 0;

    for (auto& house : houses) {
        total += getOneDistance(k, house);
    }

    return total;
}

int getOneDistance(int k, pair<int, int> house) {
    int bit = 0;
    int temp = k;
    int shortest = INT_MAX;

    while (temp > 0) {
        if (temp % 2 == 1) {
            shortest = min(shortest, abs(house.first - chickens[bit].first) + abs(house.second - chickens[bit].second));
        }
        bit++;
        temp >>= 1;
    }

    return shortest;
}
