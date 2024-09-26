#ifndef __KRUSKAL_HPP__
#define __KRUSKAL_HPP__

#include <vector>
#include <queue>

#include "disjoint_set.hpp"

namespace kruskal {
    struct Edge {
        int start;
        int end;
        int weight;

        Edge(int start, int end, int weight) : start(start), end(end), weight(weight) {}
    };

    std::vector<Edge> kruskal(std::vector<Edge> edges, int N) {
        struct cmp {
            bool operator()(const Edge& a, const Edge& b) {
                return a.weight > b.weight;
            }
        };
        
        std::priority_queue<Edge, std::vector<Edge>, cmp> pq;
        std::vector<Edge> MST;
        
        DisjointSet diset(N);

        for (auto& edge : edges) {
            pq.push(edge);
        }

        while (!pq.empty()) {
            Edge curr = pq.top();
            pq.pop();

            int start = curr.start;
            int end = curr.end;

            if (diset.find(start) != diset.find(end)) {
                MST.emplace_back(curr);
                diset.merge(start, end);
            }
        }

        return MST;
    }
}

#endif // !__KRUSKAL_HPP__
