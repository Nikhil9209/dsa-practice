#include<bits/stdc++.h>
using namespace std;
/*void Secondlargestelement(int arr[],int n ){
    int maxi = INT_MIN;
    int sec=0;

    for(int i =0;i<n;i++){
        maxi = max(maxi,arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]<maxi && arr[i]>sec)
        sec= arr[i];
    }
    cout<<sec;
}*/
// optimal approach
void Secondlargestelement(int arr[],int n ){
    int largest = 0;
    int second=INT_MIN;

    for(int i =0;i<n;i++){
        if(arr[i]>largest){
            second= largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>second){
            second=arr[i];
        }
    }
    cout<<second;
}
int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    Secondlargestelement(arr,n);
}