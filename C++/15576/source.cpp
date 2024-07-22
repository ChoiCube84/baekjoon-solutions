#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

long double const_pi(void) {
    return std::atan(1) * 4;
}

void FFT(std::vector<std::complex<long double>>& a, const std::complex<long double>& w) {
    size_t n = a.size();

    if (n == 1) {
        return;
    }

    std::vector<std::complex<long double>> a_even(n/2), a_odd(n/2);

    for (size_t i=0; i<(n/2); i++) {
        a_even[i] = a[2 * i];
        a_odd[i] = a[2 * i + 1];
    }

    std::complex<long double> w_squared = w * w;

    FFT(a_even, w_squared);
    FFT(a_odd, w_squared);

    std::complex<long double> w_i = 1;

    for (size_t i=0; i<(n/2); i++) {
        a[i] = a_even[i] + w_i * a_odd[i];
        a[i + (n/2)] = a_even[i] - w_i * a_odd[i];

        w_i *= w;
    }
}

std::vector<std::complex<long double>> convolution(std::vector<std::complex<long double>> a, std::vector<std::complex<long double>> b, bool getIntegerResult = false) {
    size_t n = 1;
    long double pi = const_pi();

    while (n <= a.size() || n <= b.size()) {
        n <<= 1;
    }
    n <<= 1;

    a.resize(n);
    b.resize(n);

    std::vector<std::complex<long double>> c(n);

    std::complex<long double> w(cos(2 * pi / n), sin(2 * pi / n));

    FFT(a, w);
    FFT(b, w);

    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }

    FFT(c, std::complex<long double>(w.real(), -w.imag()));

    for (int i = 0; i < n; i++) {
        c[i] /= std::complex<long double>(n, 0);
        if (getIntegerResult) {
            c[i] = std::complex<long double>(round(c[i].real()), round(c[i].imag()));
        }
    }

    return c;
}

template <typename T>
std::vector<T> fastMultiplication(const std::vector<T>& a, const std::vector<T>& b) {
    size_t n = a.size() + b.size() - 1;

    std::vector<std::complex<long double>> a_complex(a.begin(), a.end());
    std::vector<std::complex<long double>> b_complex(b.begin(), b.end());

    std::vector<std::complex<long double>> conv = convolution(a_complex, b_complex, true);
    std::vector<T> result(n, 0);

    for (size_t i=0; i<n; i++) {
        result[i] = static_cast<T>(conv[i].real());
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    vector<int> a(A.size()), b(B.size());

    for (int i=0; i<A.size(); i++) {
        a[i] = A[i] - '0';
    }

    for (int i=0; i<B.size(); i++) {
        b[i] = B[i] - '0';
    }

    vector<int> result = fastMultiplication(a, b);

    if (result.size() == 1 && result[0] == 0) {
        cout << 0;
        return 0;
    }

    for (int i=result.size()-1; i>0; i--) {
        result[i-1] += (result[i] / 10);
        result[i] %= 10;
    }

    bool firstDigit = true;
    for (auto& digit : result) {
        if (firstDigit && digit == 0) {
            firstDigit = false;
            continue;
        }

        firstDigit = false;
        cout << digit;
    }

    return 0;
}