#include<bits/stdc++.h>
using namespace std;
void selectionssort(int arr[],int n){
    for( int i = 0;i<=n-2;i++){
        int min =i; // n-2 per hi last element ko swap karna hai isliye n-2 tak loop chalega
        for(int j =i;j<=n-1 ;j++){ //n-1 tak hi apne ko minmum element ko find krna h isliye n-1 tak loop chalega
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}
int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    selectionssort(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }

}