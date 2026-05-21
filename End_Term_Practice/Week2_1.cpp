#include<bits/stdc++.h>
using namespace std;

int findOccur(vector<int>& arr, int n, int key, bool first){
    int low=0, high=n-1, res=-1;
    int mid=low+(high-low)/2;
    if(arr[mid]==key){
        res=mid;
        if(first){high=mid-1;}
        else{low=mid+1;}
    }
    else if(arr[mid]<key){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    return res;
}

void solve(){
    int n, key;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>key;

    int first = findOccur(arr,n,key,true);
    
    if(first==-1){
        cout<<"NO occur";
    }
    else{
        int last = findOccur(arr,n,key,false);
        cout<<key<<"-"<<last-first+1;
    }

    

    
}


