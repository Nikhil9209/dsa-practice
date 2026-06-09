#include<bits/stdc++.h>
using namespace std;
void missingnumber(int arr[],int n ){
    int maxi =arr[0];
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    map<int,int>mpp;
    for(int i =0;i<n;i++){
        
        mpp[arr[i]]++;
    }
    for(int i =0;i<n;i++){
        if(mpp[i]==0){
            cout<<i;
        }
    }

}
int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n ;i++){
        cin>>arr[i];
    }
    missingnumber(arr,n);
}