#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int result = 0;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;

        result += temp;
    }

    cout << result;
    return 0;
}