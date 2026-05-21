#include<bits/stdc++.h>
using namespace std;

bool isPath(int curr, int dest, int v, vector<vector<int>>& arr, vector<bool>& visited){
    if(curr==dest) return true;

    visited[curr]=true;

    for(int i=0; i<v; i++){
        if(arr[curr][i]==1 && !visited[i]){
            if(isPath(i, dest, v, arr, visited)){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> arr[i][j];
        }
    }
    int src, dest;
    cin>>src>>dest;
    vector<bool> visited(n, false);

    if(isPath(src, dest, n, arr, visited)){
        cout<<"yes path exists";
    }
    else cout<<"no";

}

int main(){
    solve();
    return 0;
}