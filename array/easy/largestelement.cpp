#include<bits/stdc++.h>
using namespace std;
void largestelement(int arr[],int n ){
    int maxi = INT_MIN;
    for(int i =0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    cout<<maxi;
}
int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    largestelement(arr,n);
}