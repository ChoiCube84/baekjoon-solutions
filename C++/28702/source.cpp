#include <bits/stdc++.h>

using namespace std;

string fizzbuzz(int N);

int main(void) {
    string A, B, C;
    cin >> A >> B >> C;
    
    try {
        cout << fizzbuzz(stoi(A) + 3);
    }
    catch (...) {
        try {
            cout << fizzbuzz(stoi(B) + 2);
        }
        catch (...) {
            try {
                cout << fizzbuzz(stoi(C) + 1);
            }
            catch (...) {
                
            }
        }
    }
    
    return 0;
}

string fizzbuzz(int N) {
    if (N % 3 == 0) {
        if (N % 5 == 0) {
            return "FizzBuzz";
        }
        else {
            return "Fizz";
        }
    }
    else if (N % 5 == 0) {
        return "Buzz";
    }
    else {
        return to_string(N);
    }
}
