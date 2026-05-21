#include <stdio.h>

#define MAX 20

struct Edge {
    int u, v, w;
};

int parent[MAX];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[a] = b;
}

int main() {
    int n, graph[MAX][MAX];
    struct Edge edges[MAX * MAX];
    int edgeCount = 0;

    scanf("%d", &n);

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if(graph[i][j] != 0 && i < j) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].w = graph[i][j];
                edgeCount++;
            }
        }
    }

    
    for(int i = 0; i < edgeCount - 1; i++) {
        for(int j = i + 1; j < edgeCount; j++) {
            if(edges[i].w < edges[j].w) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    
    for(int i = 0; i < n; i++)
        parent[i] = i;

    int maxWeight = 0;
    int edgesUsed = 0;

    //Kruskal
    for(int i = 0; i < edgeCount && edgesUsed < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int setU = find(u);
        int setV = find(v);

        if(setU != setV) {
            maxWeight += edges[i].w;
            unionSet(setU, setV);
            edgesUsed++;
        }
    }

    printf("Maximum Spanning Weight: %d\n", maxWeight);

    return 0;
}