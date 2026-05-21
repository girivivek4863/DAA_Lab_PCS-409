#include<bits/stdc++.h>
using namespace std;

int findMinKey(int V, vector<int>& key, vector<bool>& mstSet){
    int min = INT_MAX, min_index;
    for(int v=0; v<V; v++){
        if(!mstSet[v] && key[v]<min){
            min=key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primsMST(int V, vector<vector<int>>& graph){
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);
    key[0] = 0;

    for(int i=0; i<V-1; i++){
        int u = findMinKey(V, key, mstSet);
        mstSet[u]=true;
        
        for(int v=0; v<V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v]<key[v]){
                key[v]= graph[u][v];
            }
        }
    }
    int totalWeight=0;
    for(int i=0; i<V; i++){
        totalWeight += key[i];
    }
    cout<<"MSW"<<totalWeight<<endl;
}

int main(){
    int V;
    if(!(cin>>V)) return 0;
    vector<vector<int>> graph(V, vector<int>(V));
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cin>> graph[i][j];
        }
    }
    primsMST(V, graph);
    return 0;
}