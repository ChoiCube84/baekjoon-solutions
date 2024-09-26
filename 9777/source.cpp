#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, id;
    string birthday;
    
    vector<int> result(13, 0);
    
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> id >> birthday;
        
        stringstream ss(birthday);
        int day, month, year;
        char slash;
        
        ss >> day >> slash >> month >> slash >> year;
        result[month]++;
    }
    
    for (int i=1; i<=12; i++) {
        cout << i << " " << result[i] << "\n";
    }
    
    return 0;
}
