#include "aplusb.h"

#include <vector>
#include <utility>
#include <queue>

std::vector<int> smallest_sums(int N, std::vector<int> A, std::vector<int> B) {
    auto cmp = [&](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        return A[p1.first] + B[p1.second] > A[p2.first] + B[p2.second];
    };
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
    
    for (int i=0; i<N; i++) {
        pq.emplace(i, 0);
    }
    
    std::vector<int> result;
    
    while (result.size() < N) {
        auto [i, j] = pq.top();
        pq.pop();
        
        result.push_back(A[i] + B[j]);
        pq.emplace(i, j+1);
    }

    return result;
}
