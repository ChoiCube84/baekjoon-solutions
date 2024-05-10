#include <bits/stdc++.h>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

char dir[4] = {'U', 'D', 'L', 'R'};

bool isInRange(int N, const pair<int, int>& pos);
int getNutrient(int N, const vector<vector<int>>& sum, const pair<int, int>& upLeft, const pair<int, int>& downRight);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int N;
    cin >> N;
   
    vector<vector<int>> grid(N, vector<int>(N, 0));
    vector<vector<int>> sum(N, vector<int>(N, 0));
   
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cin >> grid[i][j];
            sum[i][j] = grid[i][j];
           
            if (i != 0) {
            sum[i][j] += sum[i-1][j];
            }
            if (j != 0) {
                sum[i][j] += sum[i][j-1];
            }
            if (i != 0 && j != 0) {
                sum[i][j] -= sum[i-1][j-1];
            }
        }
    }
   
    int nutrients = 0;
    string directions;
   
    pair<int, int> upLeft = make_pair(N / 2 - 1, N / 2 - 1);
    pair<int, int> downRight = make_pair(N / 2, N / 2);
   
    while (true) {
        pair<char, int> bestResult = make_pair(0, nutrients);
        
        for (int i=0; i<4; i++) {
            pair<int, int> newUpLeft = upLeft;
            pair<int, int> newDownRight = downRight;
            
            if (dy[i] > 0) {
                newDownRight.first += dy[i];
            }
            else {
                newUpLeft.first += dy[i];
            }
            
            if (dx[i] > 0) {
                newDownRight.second += dx[i];
            }
            else {
                newUpLeft.second += dx[i];
            }
           
            if (isInRange(N, newUpLeft) && isInRange(N, newDownRight)) {
                int newNutrient = getNutrient(N, sum, newUpLeft, newDownRight);
                
                if (newNutrient > bestResult.second) {
                   bestResult.first = dir[i];
                   bestResult.second = newNutrient;
                }
            }
        }
        
        if (bestResult.first == 0) {
            break;
        }
        else {
            nutrients = bestResult.second;
            directions += bestResult.first;
            
            switch (bestResult.first) {
            case 'U':
                upLeft.first--;
                break;
            case 'D':
                downRight.first++;
                break;
            case 'L':
                upLeft.second--;
                break;
            case 'R':
                downRight.second++;
                break;
            }
        }
    }
   
    cout << nutrients << "\n" << directions;
    
    return 0;
}

bool isInRange(int N, const pair<int, int>& pos) {
    if (pos.first < 0 || pos.first > N - 1) {
        return false;
    }
    else if (pos.second < 0 || pos.second > N - 1) {
        return false;
    }
    else {
        return true;
    }
}

int getNutrient(int N, const vector<vector<int>>& sum, const pair<int, int>& upLeft, const pair<int, int>& downRight) {
    int left = upLeft.first;
    int up = upLeft.second;
    int right = downRight.first;
    int down = downRight.second;
   
    int result = sum[down][right];
   
    if (up > 0) {
        result -= sum[up-1][right];
    }
    if (left > 0) {
        result -= sum[down][left-1];
    }
    if (up > 0 && left > 0) {
        result += sum[up-1][left-1];
    }
    
    return result;
}
