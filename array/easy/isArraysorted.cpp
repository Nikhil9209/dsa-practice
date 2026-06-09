#include<bits/stdc++.h>
using namespace std;
void isSorted(int arr[],int n ){
    int count=0;
    for(int i =0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            cout<<"array is not sorted ";
            count=1;
            break;
        }
    }
    if(count==0){
        cout<<"array is sorted";
    }
}
int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    isSorted(arr,n);
}