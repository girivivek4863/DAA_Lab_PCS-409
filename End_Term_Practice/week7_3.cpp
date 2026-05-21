#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

// Function to find shortest path with exactly k edges
long findShortestPath(vector<vector<int>>& graph, int V, int u, int v, int k) {
    // dp[e][i] stores shortest path from u to i with exactly e edges
    vector<vector<long>> dp(k + 1, vector<long>(V, INF));

    // Base case: 0 edges se source tak pahunchne ki cost 0
    dp[0][u] = 0;

    // DP transitions
    for (int e = 1; e <= k; e++) {
        for (int i = 0; i < V; i++) { // destination
            for (int j = 0; j < V; j++) { // intermediate
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

    // Adjustment for 0-based indexing if input is 1-based (Sample shows 1 4)
    long result = findShortestPath(graph, V, src - 1, dest - 1, k);

    if (result >= INF) {
        cout << "no path of length " << k << " is available" << endl;
    } else {
        cout << "Weight of shortest path from (" << src << "," << dest << ") with " << k << " edges : " << result << endl;
    }

    return 0;
}