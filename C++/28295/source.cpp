#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int direction = 0;
    
    for (int i=0; i<10; i++) {
        int instruction;
        cin >> instruction;
        
        direction += instruction;
    }
    
    switch (direction % 4) {
    case 0:
        cout << "N";
        break;
    case 1:
        cout << "E";
        break;
    case 2:
        cout << "S";
        break;
    case 3:
        cout << "W";
        break;
    }
    
    return 0;
}
