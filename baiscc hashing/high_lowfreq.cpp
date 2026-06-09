#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int mini =INT_MAX;
    int maxi =INT_MIN;

    
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mpp;;
    for(int i =0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        mini = min(mini,it.second);

    }
    for(auto it: mpp){
        maxi = max(maxi,it.second);

    }
    cout<<mini<<maxi;

}