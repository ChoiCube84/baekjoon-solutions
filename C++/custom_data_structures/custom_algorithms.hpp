#ifndef __CUSTOM_ALGORITHMS_HPP__
#define __CUSTOM_ALGORITHMS_HPP__

#include <cmath>
#include <vector>
#include <complex>
#include <string>
#include <random>
#include <numeric>

namespace custom_algorithms {
    namespace fft {
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
        std::vector<T> stringToVector(const std::string& str) {
            std::vector<T> result(str.size());

            for (size_t i=0; i<str.size(); i++) {
                result[i] = static_cast<T>(str[i] - '0');
            }

            return result;
        }

        template <typename T>
        std::string vectorToString(const std::vector<T>& vec) {
            for (size_t i=vec.size()-1; i>0; i--) {
                vec[i-1] += (vec[i] / 10);
                vec[i] %= 10;
            }

            std::string result;

            for (auto& digit : vec) {
                result += static_cast<char>(digit + '0');
            }

            return result;
        }

        std::string fastMultiplication(const std::string& A, const std::string& B) {
            std::vector<int> a = stringToVector<int>(A);
            std::vector<int> b = stringToVector<int>(B);

            size_t n = a.size() + b.size() - 1;

            std::vector<std::complex<long double>> a_complex(a.begin(), a.end());
            std::vector<std::complex<long double>> b_complex(b.begin(), b.end());

            std::vector<std::complex<long double>> conv = convolution(a_complex, b_complex, true);
            std::string result;

            for (size_t i=0; i<n; i++) {
                result[i] = static_cast<char>(static_cast<int>(conv[i].real()) + '0');
            }

            return result;
        }
    }

    namespace common {
        template <typename T>
        T stoiWithMOD(const std::string& s, const T& MOD=static_cast<T>(1)) {
            T result = static_cast<T>(0);
            for (auto& c : s) {
                result *= 10;
                result %= MOD;

                result += ((c - '0') % MOD);
                result %= MOD;
            }

            return result;
        }

        template <typename T>
        T multWithMOD_naive(const T& a, const T& b, const T& MOD=static_cast<T>(1)) {
            if (a == 0) {
                return static_cast<T>(0);
            }

            long long int digits = static_cast<long long int>(std::log10(static_cast<long double>(a)) + 1);
            T result = static_cast<T>(0);

            while (digits) {
                digits--;

                result *= 10;
                result %= MOD;

                result += ((a / static_cast<T>(std::pow(10, digits)) * b) % MOD);
                result %= MOD;
            }

            return result;
        }

        template <typename T>
        T power(const T& a, const T& b, const T& MOD=static_cast<T>(1)){
            T result = static_cast<T>(1);

            T base = a % MOD;
            T exponent = b;

            while (exponent) {
                if (exponent % 2 == 1) {
                    result = stoiWithMOD(fft::fastMultiplication(std::to_string(result), std::to_string(base)), MOD);
                }

                base = stoiWithMOD(fft::fastMultiplication(std::to_string(base), std::to_string(base)), MOD);
                exponent >>= 1;
            }

            return result;
        }

        template <typename T>
        T power_naive(const T& a, const T& b, const T& MOD=static_cast<T>(1)){
            T result = static_cast<T>(1);

            T base = a % MOD;
            T exponent = b;

            while (exponent) {
                if (exponent % 2 == 1) {
                    result = multWithMOD_naive(result, base, MOD);
                }

                base = multWithMOD_naive(base, base, MOD);
                exponent >>= 1;
            }

            return result;
        }
    }

    namespace miller_rabin {
        std::vector<int> basicPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

        bool millerRabin(unsigned long long a, unsigned long long n) {
            unsigned long long k = n-1;

            while (true) {
                unsigned long long d = common::power_naive(a, k, n);

                if (k % 2 == 1) {
                    return (d == 1 || d == n - 1);
                }
                else if (d == n - 1) {
                    return true;
                }

                k >>= 1;
            }
        }

        bool isPrime(unsigned long long n) {
            if (n <= 1) {
                return false;
            }

            for (auto& prime : basicPrimes){
                if (n == prime) {
                    return true;
                }
                else if (n % prime == 0) {
                    return false;
                }
                else if (!millerRabin(n, prime)) {
                    return false;
                }
            }

            return true;
        }
    }

    namespace pollard_rho { // WIP
        unsigned long long int findFactor(unsigned long long int n) {
            static std::mt19937_64 mt(std::random_device{}());

            static std::uniform_int_distribution<unsigned long long int> dist1(2, n);
            static std::uniform_int_distribution<unsigned long long int> dist2(1, n);

            if (n == 1) {
                return 1;
            }
            else if (n % 2 == 0) {
                return 2;
            }
            else if (miller_rabin::isPrime(n)) {
                return n;
            }
            else {
                unsigned long long int x = dist1(mt);
                unsigned long long int y = x;

                unsigned long long int c = dist2(mt);
                unsigned long long int d = 1;

                while (d == 1) {
                    x = (((x * x) % n) + c) % n;

                    y = (((y * y) % n) + c) % n;
                    y = (((y * y) % n) + c) % n;

                    d = std::gcd(n, (x > y ? x - y : y - x));

                    if (d == n) {
                        return findFactor(n);
                    }
                }

                if (miller_rabin::isPrime(d)) {
                    return d;
                }
                else {
                    return findFactor(d);
                }
            }
        }

        std::vector<std::pair<unsigned long long int, unsigned long long int>> factorize(unsigned long long int n) {
            std::vector<std::pair<unsigned long long int, unsigned long long int>> result;

            struct cmp {
                bool operator()(const std::pair<unsigned long long int, unsigned long long int>& a, const std::pair<unsigned long long int, unsigned long long int>& b) {
                    return a.first < b.first;
                }
            };

            while (n > 1) {
                unsigned long long int factor = findFactor(n);

                n /= factor;
                result.emplace_back(std::make_pair(factor, 1));

                while (n % factor == 0) {
                    n /= factor;
                    result.back().second++;
                }
            }

            sort(result.begin(), result.end(), cmp());

            return result;
        }
    }
}

#endif // __CUSTOM_ALGORITHMS_HPP__
