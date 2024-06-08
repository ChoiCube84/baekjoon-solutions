#include <bits/stdc++.h>

using namespace std;

bool xorTest(const vector<unsigned>& candidate);
vector<unsigned> makeVector(unsigned bits);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        int N;
        cin >> N;

        if (N == 1) {
            cout << "1" << "\n" << "1" << "\n";
        }
        else if (N == 2) {
            cout << "2" << "\n" << "1 2" << "\n";
        }
        else {
            int maximum = 0;
            vector<unsigned> bestCandidate;

            for (unsigned bits=1; bits<(1<<N); bits++) {
                vector<unsigned> candidate = makeVector(bits);

                if (xorTest(candidate)) {
                    if (candidate.size() > maximum) {
                        maximum = candidate.size();
                        bestCandidate = candidate;
                    }
                }
            }

            cout << maximum << "\n";

            for (auto i : bestCandidate) {
                cout << i << " ";
            }

            cout << "\n";
        }
    }

    return 0;
}

bool xorTest(const vector<unsigned>& candidate) {
    if (candidate.size() < 3) {
        if (candidate.size() == 2) {
            return ((candidate[0] ^ candidate[1]) != 0);
        }
        else {
            return true;
        }
    }

    for (int i=0; i<candidate.size()-2; i++) {
        for (int j=i+1; j<candidate.size()-1; j++) {
            for (int k=j+1; k<candidate.size(); k++) {
                if ((candidate[i] ^ candidate[j] ^ candidate[k]) == 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

vector<unsigned> makeVector(unsigned bits) {
    vector<unsigned> result;
    int curr = 1;

    while (bits > 0) {
        if (bits % 2 == 1) {
            result.emplace_back(curr);
        }
        bits >>= 1;
        curr++;
    }

    return result;
}
