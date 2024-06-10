#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string result;
    
    for (int i=0; i<225; i++) {
        char c;
        cin >> c;
        
        switch(c) {
        case 'w':
            result = "chunbae"; 
            break;
        case 'b':
            result = "nabi";
            break;
        case 'g':
            result = "yeongcheol";
            break;
        }
    }
    
    cout << result;
    
    return 0;
}
