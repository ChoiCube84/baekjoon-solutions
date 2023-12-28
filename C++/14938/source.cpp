// https://www.acmicpc.net/problem/14938
#include <bits/stdc++.h>

using namespace std;

int graph[101][101] = {0,};
int dist[101][101] = {0,};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r;
    int item[101] = {0,};

    cin >> n >> m >> r;

    for (int i=1; i<=n; i++) {
        cin >> item[i];
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i != j) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    for (int i=0; i<r; i++) {
        int start, end, weight;

        cin >> start >> end >> weight;
        graph[start][end] = min(graph[start][end], weight);
        graph[end][start] = min(graph[end][start], weight);
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = graph[i][j];
            }
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    int max_items = 0;
    int temp_items = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dist[i][j] <= m) {
                temp_items += item[j];
            }
        }

        max_items = max(max_items, temp_items);
        temp_items = 0;
    }

    cout << max_items;

    return 0;
}
