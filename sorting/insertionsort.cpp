#include<bits/stdc++.h>
using namespace std;
void innsertionSort(int arr[],int n){
    for(int i =0;i<n;i++){
        int j =i;
        while(j>0 && arr[j-1]>arr[j]){ // jab tak j 0 se bada ya barabar hai aur arr[j-1] arr[j] se bada hai tab tak loop chalega
            swap(arr[j],arr[j-1]); // arr[j] aur arr[j-1] ko swap karenge
            j--; // j ko decrement karenge
        }
    }
}
int main(){
    int n ; 
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
     innsertionSort(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    } 
}