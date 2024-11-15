#ifndef __CUSTOM_ALGORITHMS_HPP__
#define __CUSTOM_ALGORITHMS_HPP__

#include <algorithm>
#include <cmath>
#include <complex>
// #include <concepts>
#include <numeric>
#include <random>
#include <string>
#include <utility>
#include <vector>

#include "custom_data_structures/geometric_line.hpp"

namespace custom_algorithms {
    namespace fft {
		constexpr long double kPi = 3.141592653589793238462643383279502L;

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

        std::vector<std::complex<long double>> Convolution(std::vector<std::complex<long double>> a, std::vector<std::complex<long double>> b, bool getIntegerResult = false) {
            size_t n = 1;

            while (n <= a.size() || n <= b.size()) {
                n <<= 1;
            }
            n <<= 1;

            a.resize(n);
            b.resize(n);

            std::vector<std::complex<long double>> c(n);

            std::complex<long double> w(cos(2 * kPi / n), sin(2 * kPi / n));

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
        std::vector<T> StringToVector(const std::string& str) {
            std::vector<T> result(str.size());

            for (size_t i=0; i<str.size(); i++) {
                result[i] = static_cast<T>(str[i] - '0');
            }

            return result;
        }

        template <typename T>
        std::string VectorToString(const std::vector<T>& vec) {
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
        std::string FastMultiplication(const T& a, const T& b) {
            return FastMultiplication(std::to_string(a), std::to_string(b));
        }

        template <>
        std::string FastMultiplication(const std::string& A, const std::string& B) {
            std::vector<int> a = StringToVector<int>(A);
            std::vector<int> b = StringToVector<int>(B);

            size_t n = a.size() + b.size() - 1;

            std::vector<std::complex<long double>> a_complex(a.begin(), a.end());
            std::vector<std::complex<long double>> b_complex(b.begin(), b.end());

            std::vector<std::complex<long double>> conv = Convolution(a_complex, b_complex, true);
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
        T StoiWithMod(const std::string& s, const T& mod=static_cast<T>(0)) {
            T result = static_cast<T>(0);

            for (auto& c : s) {
                result *= 2;

                if (mod != 0) {
                    result %= mod;
                }

                T temp = result;

                temp *= 2;

                if (mod != 0) {
                    temp %= mod;
                }

                temp *= 2;

                if (mod != 0) {
                    temp %= mod;
                }

                result += temp;

                if (mod != 0) {
                    result %= mod;
                }

                T added = static_cast<T>(c - '0');
                if (mod != 0) {
                    added %= mod;
                }

                result += added;

                if (mod != 0) {
                    result %= mod;
                }
            }
            return result;
        }

        template <typename T>
        T MultWithModUsingInt128(const T& a, const T& b, const T& mod=static_cast<T>(0)) {
            __int128 result = a;

            result *= static_cast<__int128>(b);

            if (mod != 0) {
                result %= mod;
            }

            return result;
        }

        template <typename T>
        T Power(const T& a, const T& b, const T& mod=static_cast<T>(0), bool use_int128 = true) {
            T result = static_cast<T>(1);

            std::string (*mult)(const T&, const T&) = fft::FastMultiplication<T>;

            T base = a;
            T exponent = b;

            if (mod != 0) {
                base %= mod;
            }

            while (exponent) {
                if (exponent % 2 == 1) {
                    if (!use_int128) {
                        result = StoiWithMod(mult(result, base), mod);
                    }
                    else {
                        result = MultWithModUsingInt128(result, base, mod);
                    }
                }

                if (!use_int128) {
                    base = StoiWithMod(mult(base, base), mod);
                }
                else {
                    base = MultWithModUsingInt128(base, base, mod);
                }

                exponent >>= 1;
            }

            return result;
        }
    }

    namespace geometry {
        template <typename T>
        T InnerProduct(const std::vector<T>& u, const std::vector<T>& v) {
            if (u.size() != v.size()) {
                throw std::invalid_argument("You cannot inner product two vectors with different dimensions.");
            }

            T result = 0;
            for (size_t i=0; i<u.size(); i++) {
                result += u[i] * v[i];
            }

            return result;
        }

        template<typename T>
        T InnerProduct(const std::pair<T, T>& u, const std::pair<T, T>& v) {
            return u.first * v.first + u.second * v.second;
        }
        
        template<typename T>
        std::tuple<T, T, T> CrossProduct(const std::tuple<T, T, T>& u, const std::tuple<T, T, T>& v) {
            return std::make_tuple(
                std::get<1>(u) * std::get<2>(v) - std::get<2>(u) * std::get<1>(v),
                std::get<2>(u) * std::get<0>(v) - std::get<0>(u) * std::get<2>(v),
                std::get<0>(u) * std::get<1>(v) - std::get<1>(u) * std::get<0>(v)
            );
        }

        template <typename T>
        T GetCCW(const GeometricLine<T>& line, const std::pair<T, T>& target) {
            return std::get<2>(CrossProduct<T>(
                std::make_tuple(line.GetEnd().first - line.GetStart().first, line.GetEnd().second - line.GetStart().second, 0), 
                std::make_tuple(target.first - line.GetStart().first, target.second - line.GetStart().second, 0)));
        }
                
        namespace line_intersection {                
            enum IntersectionType {
                NON_INTERSECTION,
                INTERSECTION
            };

            template <typename T>
            IntersectionType CheckIntersection(const GeometricLine<T>& A, const GeometricLine<T>& target) {
                const T ourCCW = GetCCW(A, target.start) * GetCCW(A, target.end);
                const T theirCCW = GetCCW(target, A.start) * GetCCW(target, A.end);

                if (ourCCW == 0 && theirCCW == 0) {
                    if (A.start > target.GetEnd() || target.GetStart() > A.end) {
                        return NON_INTERSECTION;
                    }
                    else {
                        return INTERSECTION;
                    }
                }
                else if (ourCCW <= 0 && theirCCW <= 0) {
                    return INTERSECTION;
                }
                else {
                    return NON_INTERSECTION;
                }
            }
        }
        
        namespace convex_hull {             
            class CmpByCCW {
            private:
                std::pair<long long int, long long int> origin;

            public:
                CmpByCCW(const std::pair<long long int, long long int>& origin) : origin(origin) {};
                
                bool operator()(const std::pair<long long int, long long int>& a, const std::pair<long long int, long long int>& b) {
                    GeometricLine<long long int> origin_to_a(origin, a);
                    long long int ccw = GetCCW(origin_to_a, b);

                    if (ccw < 0) {
                        return false;
                    }
                    else if (ccw > 0) {
                        return true;
                    }
                    else {
                        GeometricLine<long long int> origin_to_b(origin, b);

                        long long int dx_a = origin_to_a.GetEnd().first - origin_to_a.GetStart().first;
                        long long int dy_a = origin_to_a.GetEnd().second - origin_to_a.GetStart().second;

                        long long int dx_b = origin_to_b.GetEnd().first - origin_to_b.GetStart().first;
                        long long int dy_b = origin_to_b.GetEnd().second - origin_to_b.GetStart().second;
                
                        long long int length_square_a = dx_a * dx_a + dy_a * dy_a;
                        long long int length_square_b = dx_b * dx_b + dy_b * dy_b;
                
                        return length_square_a < length_square_b;
                    }
                }
            };

            std::vector<std::pair<long long int, long long int>> GetConvexHull(const std::vector<std::pair<long long int, long long int>>& original_points) {
                std::vector<std::pair<long long int, long long int>> points = original_points;
                std::sort(points.begin(), points.end());

                CmpByCCW cmp(points[0]);
                std::sort(points.begin() + 1, points.end(), cmp);

                GeometricLine<long long int> current_line(points[0], points[1]);
                std::vector<std::pair<long long int, long long int>> convex_hull;

                convex_hull.emplace_back(points[0]);
                convex_hull.emplace_back(points[1]);

                for (size_t i=2; i<points.size(); i++) {
                    while (convex_hull.size() >= 2) {
                        long long int ccw = GetCCW(current_line, points[i]);

                        if (ccw > 0) {
                            break;
                        }
                        else {
                            convex_hull.pop_back();
                            if (convex_hull.size() == 1) {
                                break;
                            }
                        }

                        std::pair<long long int, long long int> b = convex_hull.back();
                        convex_hull.pop_back();
                        std::pair<long long int, long long int> a = convex_hull.back();
                        convex_hull.emplace_back(b);

                        current_line = GeometricLine<long long int>(a, b);
                    }

                    current_line = GeometricLine<long long int>(convex_hull.back(), points[i]);
                    convex_hull.emplace_back(points[i]);
                }

                return convex_hull;
            }
        }
    }
    
    namespace miller_rabin {
        std::vector<int> basic_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

        bool IsComposite(unsigned long long int a, unsigned long long int n, bool use_int128 = true) {
            unsigned long long int k = n - 1;

            while (true) {
                unsigned long long int d = common::Power(a, k, n, use_int128);

                if (k % 2 == 1) {
                    return (d != 1 && d != n - 1);
                }
                else if (d == n - 1) {
                    return false;
                }

                k /= 2;
            }
        }

        bool IsPrime(unsigned long long int n, bool use_int128 = true) {
            if (n <= 1) {
                return false;
            }

            for (auto& prime : basic_primes){
                if (n == prime) {
                    return true;
                }
                else if (n % prime == 0) {
                    return false;
                }
            }

            for (auto& prime : basic_primes) {
                if (IsComposite(prime, n, use_int128)) {
                    return false;
                }
            }

            return true;
        }
    }

    namespace pollard_rho {
        unsigned long long int FindFactor(unsigned long long int n, bool use_int128 = true) {
            static std::mt19937_64 mt(std::random_device{}());

            static std::uniform_int_distribution<unsigned long long int> dist1(2, n);
            static std::uniform_int_distribution<unsigned long long int> dist2(1, n);

            std::string (*mult)(const unsigned long long int&, const unsigned long long int&) = fft::FastMultiplication<unsigned long long int>;

            if (n == 1) {
                return 1;
            }
            else if (n % 2 == 0) {
                return 2;
            }
            else if (miller_rabin::IsPrime(n)) {
                return n;
            }
            else {
                unsigned long long int x = dist1(mt);
                unsigned long long int y = x;

                unsigned long long int c = dist2(mt);
                unsigned long long int d = 1;

                while (d == 1) {
                    if (!use_int128) {
                        x = (common::StoiWithMod(mult(x, x), n) + c) % n;

                        y = (common::StoiWithMod(mult(y, y), n) + c) % n;
                        y = (common::StoiWithMod(mult(y, y), n) + c) % n;
                    }
                    else {
                        x = common::MultWithModUsingInt128(x, x, n) + c;

                        y = common::MultWithModUsingInt128(y, y, n) + c;
                        y = common::MultWithModUsingInt128(y, y, n) + c;
                    }

                    d = std::gcd(n, (x > y ? x - y : y - x));

                    if (d == n) {
                        return FindFactor(n);
                    }
                }

                if (miller_rabin::IsPrime(d, use_int128)) {
                    return d;
                }
                else {
                    return FindFactor(d);
                }
            }
        }

        std::vector<std::pair<unsigned long long int, unsigned long long int>> Factorize(unsigned long long int n, bool use_int128 = true) {
            std::vector<std::pair<unsigned long long int, unsigned long long int>> result;

            struct cmp {
                bool operator()(const std::pair<unsigned long long int, unsigned long long int>& a, const std::pair<unsigned long long int, unsigned long long int>& b) {
                    return a.first < b.first;
                }
            };

            while (n > 1) {
                unsigned long long int factor = FindFactor(n, use_int128);

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
        unsigned long long int Phi(unsigned long long int n) {
            unsigned long long int result = 1;
            auto factors = pollard_rho::Factorize(n);

            for (auto& [factor, power] : factors) {
                result *= common::Power(factor, power-1) * (factor-1);
            }

            return result;
        }
    }

    namespace shortest_path {
        namespace floyd_warshall {
            template <template<typename, typename> typename Table, typename Node, typename Distance>
            Table<Node, Table<Node, Distance>> GetShortestPath(const Table<Node, Table<Node, Distance>>& graph) {
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
			namespace {
				template <typename Node, typename Distance>
				struct cmp {
                    bool operator()(const std::pair<Node, Distance>& a, const std::pair<Node, Distance>& b) {
                        return b.second < a.second;
                    }
                };
			}
			
			template <typename Node, typename Distance>
			std::vector<Distance> GetShortestPath(const std::vector<std::vector<std::pair<Node, Distance>>>& graph, const Node& start) {
				std::vector<Distance> distance(graph.size());
				std::fill(distance.begin(), distance.end(), -1);
				
				distance[start] = 0;
				
				std::priority_queue<std::pair<Node, Distance>, std::vector<std::pair<Node, Distance>>, cmp<Node, Distance>> pq;
                pq.push(std::make_pair(start, 0));

                while (!pq.empty()) {
                    auto [currNode, currDist] = pq.top();
                    pq.pop();

                    if (distance[currNode] != -1 && distance[currNode] < currDist) {
                        continue;
                    }

                    for (auto [next, weight] : graph[currNode]) {
                        if (weight < 0) {
							std::fill(distance.begin(), distance.end(), -1);
                            return distance;
                        }
                        if (distance[next] == -1 || currDist + weight < distance[next]) {
                            distance[next] = currDist + weight;
                            pq.push(std::make_pair(next, distance[next]));
                        }
                    }
                }

                return distance;
			}
			
            template <template<typename, typename> typename Table, typename Node, typename Distance>
            Table<Node, Distance> GetShortestPath(Table<Node, Table<Node, Distance>>& graph, const Node& start) {
                Table<Node, Distance> distance;
                distance[start] = 0;

                std::priority_queue<std::pair<Node, Distance>, std::vector<std::pair<Node, Distance>>, cmp<Node, Distance>> pq;
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
                        if (distance.find(next) == distance.end() || currDist + weight < distance[next]) {
                            distance[next] = currDist + weight;
                            pq.push(std::make_pair(next, distance[next]));
                        }
                    }
                }

                return distance;
            }
			
			// template<typename State, typename Distance>
			// concept HasGetNextStates = requires(State state) {
			// 	{
			// 		state.GetNextStates()
			// 	}
			// 	-> std::same_as<std::vector<std::pair<State, Distance>>>;
			// };
			
			// // TODO: Complete this GetShortestPath function!
			// template <template<typename, typename> typename Table, typename State, typename Distance>
			// requires HasGetNextStates<State>
			// Table<State, Distance> GetShortestPath(const Node& start, bool bKeepOnlyTerminalState = true) {
			// 	Table<Node, Distance> distance;
			// 	distance[start] = 0;

			// 	std::priority_queue<std::pair<Node, Distance>, std::vector<std::pair<Node, Distance>>, cmp<Node, Distance>> pq;
			// 	pq.push(std::make_pair(start, 0));

			// 	while (!pq.empty()) {
			// 		auto [currNode, currDist] = pq.top();
			// 		pq.pop();

			// 		if (distance.find(currNode) != distance.end() && distance[currNode] < currDist) {
			// 			continue;
			// 		}

			// 		auto next_states = currNode.GetNextStates();

			// 		for (auto [next, weight] : next_states) {
			// 			if (weight < 0) {
			// 				distance.clear();
			// 				return distance;
			// 			}
			// 			if (distance.find(next) == distance.end() || currDist + weight < distance[next]) {
			// 				distance[next] = currDist + weight;
			// 				pq.push(std::make_pair(next, distance[next]));
			// 			}
			// 		}
			// 	}

			// 	return distance;
			// }
        }
    }
}

#endif // __CUSTOM_ALGORITHMS_HPP__
