#ifndef __CUSTOM_ALGORITHMS_HPP__
#define __CUSTOM_ALGORITHMS_HPP__

#include <cmath>
#include <vector>
#include <complex>
#include <string>

namespace custom_algorithms {
    namespace common {
        template <typename T>
        T power(const T& a, const T& b, const T& MOD=static_cast<T>(1)){
            T result = static_cast<T>(1);
            a %= MOD;

            while (b) {
                if (m % 2) {
                    result = stoiWithMOD(fft::fastMultication(to_string(result), to_string(a)), MOD);
                }

                a = stoiWithMOD(fft::fastMultication(to_string(a), to_string(a)), MOD);
                b >>= 1;
            }

            return result;
        }

        template <typename T>
        T stoiWithMOD(const string& s, const T& MOD=static_cast<T>(1)) {
            T result = static_cast<T>(0);
            for (auto& c : s) {
                result *= 10;
                result %= MOD;
                
                result += ((c - '0') % MOD);
                result %= MOD;
            }

            return result;
        }
    }
    
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
        std::vector<T> vectorToString(const std::vector<T>& vec) {
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
            std::vector<T> result(n, 0);

            for (size_t i=0; i<n; i++) {
                result[i] = static_cast<T>(conv[i].real());
            }

            return result;
        }
    }

    namespace miller_rabin {
        std::vector<int> basicPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

        bool millerRabin(unsigned long long a, unsigned long long n) {
            unsigned long long k = n-1;

            while (true) {
                unsigned long long d = common::power(a, k, n);
                
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
            
            for (auto& prime : primes){
                if (n == prime) {
                    return true;
                }
                else if (n % prime == 0) {
                    return false;
                }
                else if (!millerRabin(N, prime)) {
                    return false;
                }
            }
            
            return true;
        }
    }
}

#endif // __CUSTOM_ALGORITHMS_HPP__