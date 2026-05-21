#include<bits/stdc++.h>
using namespace std;

bool isPath(int u, int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack){
    visited[u]=true;
    recStack[u]=true;

    for(int next=0; next<v; next++){
        if(adj[u][next]==1){
            if(recStack[next]) return true;

            if(!visited[next] && isPath(next, v, adj, visited, recStack)){
                return true;
            }
        }
    }
    recStack[u]=false;
    return false;
}

void solve(){
    int v;
    if(!(cin>>v)) return;
    vector<vector<int>> adj(v, vector<int>(v));

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            cin>> adj[i][j];
        }
    }

    vector<bool> visited(v, false);
    vector<bool> recStack(v, false);
    bool found = false;

    for(int i=0; i<v; i++){
        if(!(visited[i])){
            if(isPath(i, v, adj, visited, recStack)){
                found=true;
                break;
            }
        }
    }
    if(found)cout<<"Cycle exists"<<endl;
    else cout<<"No cycle exists"<<endl;
}

int main(){
    solve();
    return 0;
}