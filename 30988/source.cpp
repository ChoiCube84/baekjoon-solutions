#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void handle1(const vector<ll>& a);
void handle4(const vector<ll>& a);
void handle9(const vector<ll>& a);
void handle16(const vector<ll>& a);
void handle25(const vector<ll>& a);

bool coeffSearch(const vector<ll>& a, vector<ll>& b, int aCoeffIndex, int bCoeffIndex);

bool coeffInRange(ll b);
ll nSqrt(ll a, unsigned int n);

vector<ll> polyPow(const vector<ll>& b, unsigned int n);
vector<ll> polyAdd(const vector<ll>& a, const vector<ll>& b);
vector<ll> polyMulti(ll c, const vector<ll>& b);
vector<ll> polyProduct(const vector<ll>& a, const vector<ll>& b);

vector<ll> getRecursivePoly(const vector<ll>& b);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n+1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());

    switch (n) {
        case 1:
            handle1(a);
            break;
        case 4:
            handle4(a);
            break;
        case 9:
            handle9(a);
            break;
        case 16:
            handle16(a);
            break;
        case 25:
            handle25(a);
            break;
        default:
            cout << "-1";
            break;
    }

    return 0;
}

void handle1(const vector<ll>& a) {
    ll b1 = static_cast<ll>(sqrt(abs(a[1])));
    if (b1 > 100) {
        cout << -1;
    }
    else if (b1 * b1 != a[1]) {
        cout << -1;
    }
    else if (a[0] % (b1 + 1) == 0) {
        ll b0 = a[0] / (b1 + 1);
        if (coeffInRange(b0)) {
            cout << 1 << "\n";
            cout << b1 << " " << a[0] / (b1 + 1);
        }
        else {
            cout << -1;
        }
    }
    else if (b1 == 1) {
        if (a[0] == 0) {
            cout << 1 << "\n";
            cout << -b1 << " " << 0;
        }
        else {
            cout << -1;
        }
    }
    else if (a[0] % (-b1 + 1) == 0) {
        ll b0 = a[0] / (-b1 + 1);
        if (coeffInRange(b0)) {
            cout << 1 << "\n";
            cout << -b1 << " " << b0;
        }
        else {
            cout << -1;
        }
    }
    else {
        cout << -1;
    }
}

void handle4(const vector<ll>& a) {
    ll b2 = static_cast<ll>(nSqrt(abs(a[4]), 3));
    if (a[4] < 0) {
        b2 = -b2;
    }

    if (b2 * b2 * b2 != a[4]) {
        cout << -1;
    }
    else {
        vector<ll> b;
        vector<ll> b1_possible;

        bool found = false;

        b.resize(3, 0);
        b[2] = b2;

        found = coeffSearch(a, b, 3, 1);

        if (found) {
            cout << 2 << "\n";
            for (int i=(b.size() - 1); i>=0; i--) {
                cout << b[i] << " ";
            }
        }
        else {
            cout << -1;
        }
    }
}

void handle9(const vector<ll>& a) {
    ll b3 = static_cast<ll>(nSqrt(abs(a[9]), 4));
    if (a[9] < 0) {
        b3 = -b3;
    }

    ll b3_square = b3 * b3;
    if (b3_square * b3_square != a[9]) {
        cout << -1;
    }
    else {
        vector<ll> b;
        bool found = false;

        b.resize(4, 0);

        b[3] = b3;
        found = coeffSearch(a, b, 8, 2);

        if (!found) {
            b[3] = -b3;
            found = coeffSearch(a, b, 8, 2);
        }

        if (found) {
            cout << 3 << "\n";
            for (int i=(b.size() - 1); i>=0; i--) {
                cout << b[i] << " ";
            }
        }
        else {
            cout << -1;
        }
    }
}

void handle16(const vector<ll>& a) {
    ll b4 = static_cast<ll>(nSqrt(abs(a[16]), 5));
    if (a[16] < 0) {
        b4 = -b4;
    }

    ll b4_square = b4 * b4;
    if (b4_square * b4_square * b4 != a[16]) {
        cout << -1;
    }
    else {
        vector<ll> b;
        bool found = false;

        b.resize(5, 0);
        b[4] = b4;

        found = coeffSearch(a, b, 15, 3);

        if (found) {
            cout << 4 << "\n";
            for (int i=(b.size() - 1); i>=0; i--) {
                cout << b[i] << " ";
            }
        }
        else {
            cout << -1;
        }
    }
}

void handle25(const vector<ll>& a) {
    ll b5 = static_cast<ll>(nSqrt(abs(a[25]), 6));
    if (a[25] < 0) {
        b5 = -b5;
    }

    ll b5_square = b5 * b5;
    if (b5_square * b5_square * b5_square != a[25]) {
        cout << -1;
    }
    else {
        vector<ll> b;
        bool found = false;

        b.resize(6, 0);
        b[5] = b5;

        found = coeffSearch(a, b, 24, 4);

        if (!found) {
            b[5] = -b5;

            found = coeffSearch(a, b, 24, 4);
        }

        if (found) {
            cout << 5 << "\n";
            for (int i=(b.size() - 1); i>=0; i--) {
                cout << b[i] << " ";
            }
        }
        else {
            cout << -1;
        }
    }
}

bool coeffSearch(const vector<ll>& a, vector<ll>& b, int aCoeffIndex, int bCoeffIndex) {
    bool found = false;

    if (bCoeffIndex == 0) {
        for (b[0] = -100; b[0] <= 100; b[0]++) {
            if (getRecursivePoly(b) == a) {
                found = true;
                break;
            }
        }
    }
    else {
        for (b[bCoeffIndex] = -100; b[bCoeffIndex] <= 100; b[bCoeffIndex]++) {
            if (getRecursivePoly(b)[aCoeffIndex] == a[aCoeffIndex]) {
                found = coeffSearch(a, b, aCoeffIndex - 1, bCoeffIndex - 1);
            }

            if (found) {
                break;
            }
        }
    }

    return found;
}

bool coeffInRange(ll b) {
    return abs(b) <= 100;
}

ll nSqrt(ll a, unsigned int n) {
    ll result = static_cast<ll>(pow(a, 1.0/n));

    while (pow(result, n) < a) {
        result++;
    }

    return result;
}

vector<ll> polyPow(const vector<ll>& b, unsigned int n) {
    vector<ll> result;

    if (n == 0) {
        result.emplace_back(1);
    }
    else if (n == 1) {
        result = b;
    }
    else {
        vector<ll> halfPowered = polyPow(b, n / 2);
        result = polyProduct(halfPowered, halfPowered);
        if (n % 2 == 1) {
            result = polyProduct(result, b);
        }
    }

    return result;
}

vector<ll> polyAdd(const vector<ll>& a, const vector<ll>& b) {
    int n = a.size() - 1;
    int m = b.size() - 1;

    int k = max(n, m);
    int l = min(n, m);

    vector<ll> result(k+1, 0);

    for (int i=0; i<=l; i++) {
        result[i] = a[i] + b[i];
    }
    if (m == k) {
        for (int i=l+1; i<=k; i++) {
            result[i] = b[i];
        }
    }
    else {
        for (int i=l+1; i<=k; i++) {
            result[i] = a[i];
        }
    }

    return result;
}

vector<ll> polyMulti(ll c, const vector<ll>& b) {
    vector<ll> result = b;

    for (long long & i : result) {
        i *= c;
    }

    return result;
}

vector<ll> polyProduct(const vector<ll>& a, const vector<ll>& b) {
    int n = a.size() - 1;
    int m = b.size() - 1;

    vector<ll> result(n+m+1, 0);

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            result[i+j] += a[i] * b[j];
        }
    }

    return result;
}

vector<ll> getRecursivePoly(const vector<ll>& b) {
    int m = b.size() - 1;
    vector<ll> result(m * m, 0);

    for (int i=0; i<=m; i++) {
        result = polyAdd(result, polyMulti(b[i], polyPow(b, i)));
    }

    return result;
}
