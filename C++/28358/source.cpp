#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int daysInMonth(int month);
bool numberFound(int target, int number);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t=0; t<T; t++) {
        vector<int> numbers(10, 0);
        for (int i=0; i<10; i++) {
            cin >> numbers[i];
        }

        int result = 366;

        for (int month=1; month<=12; month++) {
            for (int day=1; day<=daysInMonth(month); day++) {
                for (int n=0; n<10; n++) {
                    if (numbers[n] == 0) {
                        continue;
                    }

                    if (numberFound(month, n) || numberFound(day, n)) {
                        result--;
                        break;
                    }
                }
            }
        }

        cout << result << '\n';
    }

    return 0;
}

int daysInMonth(int month) {
    switch (month) {
    case 1:
        return 31;
    case 2:
        return 29;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    }

    return 0;
}

bool numberFound(int target, int number) {
    if (target % 10 == number || (target >= 10 && target / 10 == number)) {
        return true;
    }
    else {
        return false;
    }
}