#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string dice[4];
    for (int i=0; i<4; i++) {
        cin >> dice[i];
    }

    int permutations[24][4] = {
        {0, 1, 2, 3},
        {0, 1, 3, 2},
        {0, 2, 1, 3},
        {0, 2, 3, 1},
        {0, 3, 1, 2},
        {0, 3, 2, 1},
        {1, 0, 2, 3},
        {1, 0, 3, 2},
        {1, 2, 0, 3},
        {1, 2, 3, 0},
        {1, 3, 0, 2},
        {1, 3, 2, 0},
        {2, 0, 1, 3},
        {2, 0, 3, 1},
        {2, 1, 0, 3},
        {2, 1, 3, 0},
        {2, 3, 0, 1},
        {2, 3, 1, 0},
        {3, 0, 1, 2},
        {3, 0, 2, 1},
        {3, 1, 0, 2},
        {3, 1, 2, 0},
        {3, 2, 0, 1},
        {3, 2, 1, 0},
    };
    
    unordered_set<string> combinations;

    for (int permutation=0; permutation<24; permutation++) {
        for (int dice1=0; dice1<7; dice1++) {
            for (int dice2=0; dice2<7; dice2++) {
                for (int dice3=0; dice3<7; dice3++) {
                    for (int dice4=0; dice4<7; dice4++) {
                        string combination;

                        if (dice1 < 6) {
                            combination += dice[permutations[permutation][0]][dice1];
                        }

                        if (dice2 < 6) {
                            combination += dice[permutations[permutation][1]][dice2];
                        }

                        if (dice3 < 6) {
                            combination += dice[permutations[permutation][2]][dice3];
                        }

                        if (dice4 < 6) {
                            combination += dice[permutations[permutation][3]][dice4];
                        }
                        
                        combinations.insert(combination);
                    }
                }
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        string query;
        cin >> query;

        if (combinations.find(query) != combinations.end()) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}