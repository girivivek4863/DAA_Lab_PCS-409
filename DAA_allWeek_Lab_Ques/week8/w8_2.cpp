#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, weight;
};

bool compEdges(edge a, edge b){
    return a.weight<b.weight;
}

struct DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(i);
    }

    void unite(int i, int j){
        int root_i = find(i);
        int root_j = find(j);
        if(root_i != root_j){
            parent[i] = root_j;
        }
    }
};

void kruskalMST(int V, vector<edge>& edges){
    sort(edges.begin(), edges.end(), compEdges);

    DSU dsu(V);
    int totalWeight = 0;
    int totalCount = 0;

    for(auto & edge : edges){
        if(dsu.find(edge.u) != dsu.find(edge.v)){
            dsu.unite(edge.u, edge.v);
            totalWeight += edge.weight;
            totalCount++;
        }
        if(totalCount == V-1) break;
    }
    cout<<"MSW"<<totalWeight;
}

int main(){
    int V;
    if(!(cin>>V)) return 0;
    vector<edge> edges; 

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            int w;
            cin>>w;
            if(i<j && w!=0){
                edges.push_back({i,j,w});
            }
        }
    }
    kruskalMST(V, edges);
    return 0;
}