#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int n){

    if(n == 1){
        return;
    }

    // One pass
    for(int j = 0; j <= n-2; j++){

        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }

    bubblesort(arr, n-1);
}

int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bubblesort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}