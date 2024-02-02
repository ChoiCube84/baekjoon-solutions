#ifndef __KNAPSACK_HPP__
#define __KNAPSACK_HPP__

#include <vector>

template <typename T>
T knapsack(const std::vector<T>& weight, const std::vector<T>& value, const T& maxWeight) {
    if (weight.size() != value.size()) {
        return static_cast<T>(0);
    }

    size_t n = weight.size();
    std::vector<std::vector<T>> dp(n + 1, std::vector<T>(maxWeight + 1, 0));

    for (size_t i=1; i<=n; i++) {
        for (T w=0; w<=maxWeight; w++) {
            T without = dp[i-1][w];

            if (weight[i - 1] <= w) {
                T with = value[i-1] + dp[i-1][w - weight[i-1]];
                dp[i][w] = with > without ? with : without;
            }
            else {
                dp[i][w] = without;
            }
        }
    }

    return dp[n][maxWeight];
}

#endif //__KNAPSACK_HPP__
