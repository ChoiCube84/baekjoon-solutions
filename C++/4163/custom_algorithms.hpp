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

        template <typename T>
        std::string fastMultiplication(const T& A, const T& B) {
            return fastMultiplication(std::to_string(A), std::to_string(B));
        }

        template <>
        std::string fastMultiplication(const std::string& A, const std::string& B) {
            std::vector<int> a = stringToVector<int>(A);
            std::vector<int> b = stringToVector<int>(B);

            size_t n = a.size() + b.size() - 1;

            std::vector<std::complex<long double>> a_complex(a.begin(), a.end());
            std::vector<std::complex<long double>> b_complex(b.begin(), b.end());

            std::vector<std::complex<long double>> conv = convolution(a_complex, b_complex, true);
            std::vector<int> digitArray(n, 0);

            for (size_t i=0; i<n; i++) {
                digitArray[i] = static_cast<int>(conv[i].real());
            }

            for (int i=digitArray.size()-1; i>0; i--) {
                digitArray[i-1] += (digitArray[i] / 10);
                digitArray[i] %= 10;
            }

            std::string result;
            for (auto& digit : digitArray) {
                result += std::to_string(digit);
            }

            return result;
        }
    }

    namespace common {
        template <typename T>
        T stoiWithMOD(const std::string& s, const T& MOD=static_cast<T>(0)) {
            T result = static_cast<T>(0);

            for (auto& c : s) {
                result *= 2;

                if (MOD != 0) {
                    result %= MOD;
                }

                T temp = result;

                temp *= 2;

                if (MOD != 0) {
                    temp %= MOD;
                }

                temp *= 2;

                if (MOD != 0) {
                    temp %= MOD;
                }

                result += temp;

                if (MOD != 0) {
                    result %= MOD;
                }

                T added = static_cast<T>(c - '0');
                if (MOD != 0) {
                    added %= MOD;
                }

                result += added;

                if (MOD != 0) {
                    result %= MOD;
                }
            }
            return result;
        }

        template <typename T>
        T multWithMOD_int128(const T& a, const T& b, const T& MOD=static_cast<T>(0)) {
            __int128 result = a;

            result *= static_cast<__int128>(b);

            if (MOD != 0) {
                result %= MOD;
            }

            return result;
        }

        template <typename T>
        T power(const T& a, const T& b, const T& MOD=static_cast<T>(0), bool useInt128 = true){
            T result = static_cast<T>(1);

            std::string (*mult)(const T&, const T&) = fft::fastMultiplication<T>;

            T base = a;
            T exponent = b;

            if (MOD != 0) {
                base %= MOD;
            }

            while (exponent) {
                if (exponent % 2 == 1) {
                    if (!useInt128) {
                        result = stoiWithMOD(mult(result, base), MOD);
                    }
                    else {
                        result = multWithMOD_int128(result, base, MOD);
                    }
                }

                if (!useInt128) {
                    base = stoiWithMOD(mult(base, base), MOD);
                }
                else {
                    base = multWithMOD_int128(base, base, MOD);
                }

                exponent >>= 1;
            }

            return result;
        }
    }

    namespace miller_rabin {
        std::vector<int> basicPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

        bool isComposite(unsigned long long int a, unsigned long long int n, bool useInt128 = true) {
            unsigned long long int k = n - 1;

            while (true) {
                unsigned long long int d = common::power(a, k, n, useInt128);

                if (k % 2 == 1) {
                    return (d != 1 && d != n - 1);
                }
                else if (d == n - 1) {
                    return false;
                }

                k /= 2;
            }
        }

        bool isPrime(unsigned long long int n, bool useInt128 = true) {
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
            }

            for (auto& prime : basicPrimes) {
                if (isComposite(prime, n, useInt128)) {
                    return false;
                }
            }

            return true;
        }
    }

    namespace pollard_rho {
        unsigned long long int findFactor(unsigned long long int n, bool useInt128 = true) {
            static std::mt19937_64 mt(std::random_device{}());

            static std::uniform_int_distribution<unsigned long long int> dist1(2, n);
            static std::uniform_int_distribution<unsigned long long int> dist2(1, n);

            std::string (*mult)(const unsigned long long int&, const unsigned long long int&) = fft::fastMultiplication<unsigned long long int>;

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
                    if (!useInt128) {
                        x = (common::stoiWithMOD(mult(x, x), n) + c) % n;

                        y = (common::stoiWithMOD(mult(y, y), n) + c) % n;
                        y = (common::stoiWithMOD(mult(y, y), n) + c) % n;
                    }
                    else {
                        x = common::multWithMOD_int128(x, x, n) + c;

                        y = common::multWithMOD_int128(y, y, n) + c;
                        y = common::multWithMOD_int128(y, y, n) + c;
                    }

                    d = std::gcd(n, (x > y ? x - y : y - x));

                    if (d == n) {
                        return findFactor(n);
                    }
                }

                if (miller_rabin::isPrime(d, useInt128)) {
                    return d;
                }
                else {
                    return findFactor(d);
                }
            }
        }

        std::vector<std::pair<unsigned long long int, unsigned long long int>> factorize(unsigned long long int n, bool useInt128 = true) {
            std::vector<std::pair<unsigned long long int, unsigned long long int>> result;

            struct cmp {
                bool operator()(const std::pair<unsigned long long int, unsigned long long int>& a, const std::pair<unsigned long long int, unsigned long long int>& b) {
                    return a.first < b.first;
                }
            };

            while (n > 1) {
                unsigned long long int factor = findFactor(n, useInt128);

                n /= factor;
                result.emplace_back(std::make_pair(factor, 1));

                while (n % factor == 0) {
                    n /= factor;
                    result.back().second++;
                }
            }

            std::sort(result.begin(), result.end(), cmp());

            return result;
        }
    }

    namespace euler_totient {
        unsigned long long int phi(unsigned long long int n) {
            unsigned long long int result = 1;
            auto factors = pollard_rho::factorize(n);

            for (auto& [factor, power] : factors) {
                result *= common::power(factor, power-1) * (factor-1);
            }

            return result;
        }
    }

    namespace shortest_path {
        namespace floyd_warshall {
            template <template<typename, typename> typename Table, typename Node, typename Distance>
            Table<Node, Table<Node, Distance>> getShortestPath(const Table<Node, Table<Node, Distance>>& graph) {
                Table<Node, Table<Node, Distance>> distance = graph;

                for (auto [middle, _] : distance) {
                    for (auto [start, _] : distance) {
                        for (auto [end, _] : distance) {
                            if (distance[start][end] > distance[start][middle] + distance[middle][end]) {
                                distance[start][end] = distance[start][middle] + distance[middle][end];
                            }
                        }
                    }
                }

                return distance;
            }
        }

        namespace dijkstra {
            template <template<typename, typename> typename Table, typename Node, typename Distance>
            Table<Node, Distance> getShortestPath(Table<Node, Table<Node, Distance>>& graph, const Node& start) {
                Table<Node, Distance> distance;
                distance[start] = 0;

                struct cmp {
                    bool operator()(const std::pair<Node, Distance>& a, const std::pair<Node, Distance>& b) {
                        return a.second > b.second;
                    }
                };

                std::priority_queue<std::pair<Node, Distance>, std::vector<std::pair<Node, Distance>>, cmp> pq;
                pq.push(std::make_pair(start, 0));

                while (!pq.empty()) {
                    auto [currNode, currDist] = pq.top();
                    pq.pop();

                    if (distance.find(currNode) != distance.end() && distance[currNode] < currDist) {
                        continue;
                    }

                    for (auto [next, weight] : graph[currNode]) {
                        if (weight < 0) {
                            distance.clear();
                            return distance;
                        }
                        if (distance.find(next) == distance.end() || distance[next] > currDist + weight) {
                            distance[next] = currDist + weight;
                            pq.push(std::make_pair(next, distance[next]));
                        }
                    }
                }

                return distance;
            }
        }
    }
}

#endif // __CUSTOM_ALGORITHMS_HPP__
