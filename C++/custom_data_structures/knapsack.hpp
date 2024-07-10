#ifndef __KNAPSACK_HPP__
#define __KNAPSACK_HPP__

#include <vector>

template <typename T>
class Knapsack {
private:
    std::vector<T> weight;
    std::vector<T> value;
    T maxWeight;

    std::vector<std::vector<T>> dp;
public:
    Knapsack(const std::vector<T>& weight, const std::vector<T>& value, T maxWeight) 
        : weight(weight), value(value), maxWeight(maxWeight), 
        dp(std::vector<std::vector<T>>(weight.size() + 1, std::vector<T>(maxWeight + 1, 0))) 
    {        
        size_t n = weight.size();

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
    }

    const T& getMaxValue(T capacity = maxWeight) {
        return dp[weight.size()][capacity];
    }
}

#endif //__KNAPSACK_HPP__
