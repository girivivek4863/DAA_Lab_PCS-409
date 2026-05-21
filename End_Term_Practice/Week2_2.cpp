#include<bits/stdc++.h>
using namespace std;

void triplet(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bool found = false;
     for(int k=n-1; k>=2; k--){
        int i=0;
        int j=k-1;
        while(i<j){
            if(arr[i]+arr[j]==arr[k]){
                found = true;
                cout<<i+1<<j+1<<k+1;
                return;
            }
            else if(arr[i]+arr[k]<arr[k]){
                i++;
            }
            else j--;
        }
     }
     if(!found) cout<<"No triplet";
}

int main(){
    
}