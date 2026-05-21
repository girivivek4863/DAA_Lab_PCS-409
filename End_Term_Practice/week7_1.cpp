#include<bits/stdc++.h>
using namespace std;

void printPath(int j, vector<int>& parent){
    if(parent[j]==-1){
        cout<<j+1;
        return;
    }
    printPath(parent[j], parent);
    cout<<" "<<j+1;
}

void dijkstra(){
    int v;
    if(!(cin>>v)) return;
    vector<vector<int>> adj(v, vector<int>(v));
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cin>>adj[i][j];
        }
    }

    vector<int> dist(v, INT_MAX);
    vector<bool> visited(v, false);
    vector<int> parent(v, -1);

    int src;
    cin>>src;
    src--;

    dist[src]=0;

    for(int count=0; count<v-1; count++){
        int min_dist=INT_MAX, u;
        for(int i=0; i<v; i++){
            if(!visited[i] && dist[i]<=min_dist){
                min_dist=dist[i];
                u=i;
            }
        }

        visited[u]=true;

        for(int i=0; i<v; i++){
            if(!visited[i] && adj[u][i] && dist[u]!=INT_MAX && dist[u]+adj[u][i]<dist[i]){
                dist[i]= dist[u]+adj[u][i];
                parent[i]=u;
            }
        }
    }

    for(int i=0; i<v; i++){
        printPath(i, parent);
            cout<<":"<< dist[i]<<endl;
    }
}

int main(){
    dijkstra();
    return 0;
}