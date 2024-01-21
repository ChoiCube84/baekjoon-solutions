#include <bits/stdc++.h>

using namespace std;

struct Cord {
    int start;
    int end;

    bool operator<(const Cord& other) const {
        return (this->start < other.start);
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<Cord> cords;

    for (int i=0; i<n; i++) {
        int start, end;
        cin >> start >> end;

        cords.push_back({start, end});
    }

    sort(cords.begin(), cords.end());

    vector<int> arr;
    vector<int> lisIndex(n, 0);
    vector<int> lis;

    for (auto& cord : cords) {
        arr.emplace_back(cord.end);
    }

    for (int i=0; i<n; i++) {
        int curr = arr[i];

        if (i == 0 || curr > lis.back()) {
            lis.emplace_back(curr);
            lisIndex[i] = lis.size() - 1;
        }
        else {
            int index = lower_bound(lis.begin(), lis.end(), curr) - lis.begin();
            lis[index] = curr;
            lisIndex[i] = index;
        }
    }

    int lisLength = lis.size();

    stack<int> s;
    int curr = lisLength - 1;

    for (int i=n-1; curr >= 0; i--) {
        if (lisIndex[i] == curr) {
            s.push(arr[i]);
            curr--;
        }
    }

    cout << n - lisLength << "\n";

    for (int i=0; i<n; i++) {
        if (!s.empty() && arr[i] == s.top()) {
            s.pop();
        }
        else {
            cout << cords[i].start << "\n";
        }
    }

    return 0;
}
