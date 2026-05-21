#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX


long findShortestPath(vector<vector<int>>& graph, int V, int u, int v, int k) {
    
    vector<vector<long>> dp(k + 1, vector<long>(V, INF));

    
    dp[0][u] = 0;

    
    for (int e = 1; e <= k; e++) {
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (graph[j][i] != 0 && dp[e - 1][j] != INF) {
                    if (dp[e][i] > dp[e - 1][j] + graph[j][i]) {
                        dp[e][i] = dp[e - 1][j] + graph[j][i];
                    }
                }
            }
        }
    }

    return dp[k][v];
}

int main() {
    int V;
    if (!(cin >> V)) return 0;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int src, dest, k;
    cin >> src >> dest >> k;

    
    long result = findShortestPath(graph, V, src - 1, dest - 1, k);

    if (result >= INF) {
        cout << "no path of length " << k << " is available" << endl;
    } else {
        cout << "Weight of shortest path from (" << src << "," << dest << ") with " << k << " edges : " << result << endl;
    }

    return 0;
}