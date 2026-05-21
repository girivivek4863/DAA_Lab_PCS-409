#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define INF 1e9

struct Edge {
    int u, v, w;
};

void printPath(int current, vector<int>& parent) {
    if (current == -1) return;
    printPath(parent[current], parent);
    cout << current + 1 << " "; // 1-based indexing for output
}

void bellmanFord(int V, vector<Edge>& edges, int src) {
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                parent[edge.v] = edge.u;
            }
        }
    }

    // Output formatting according to manual sample
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            cout << i + 1 << " : No Path" << endl;
        } else {
            // Path structure needs to be reversed or printed recursively
            vector<int> path;
            for (int curr = i; curr != -1; curr = parent[curr]) {
                path.push_back(curr + 1);
            }
            // Sample output shows path from target to source? 
            // Manual: "path from destination vertex number to source"
            for (int p : path) cout << p << " ";
            cout << ":" << dist[i] << endl;
        }
    }
}

int main() {
    int V;
    cin >> V;

    vector<Edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                edges.push_back({i, j, weight});
            }
        }
    }

    int src;
    cin >> src;
    bellmanFord(V, edges, src - 1);

    return 0;
}