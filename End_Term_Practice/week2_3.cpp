#include<bits/stdc++.h>
using namespace std;

void findDiffPairs(){
    int n, key;
    cin>>n;
    vector<int> arr(n);
     for(int i=0; i<n; i++){
        cin>>arr[i];
     }
     cin>>key;

     sort(arr.begin(), arr.end());

     int i=0, j=1, count=0;
     
     while(j<n){
        int diff = arr[j]-arr[i];
        if(diff==key){
            count++;
            i++;
            j++;
        }
        else if(diff<key) j++;
        else i++;

        if(i=j) j++;
     }
     cout<<count<<endl;
}

