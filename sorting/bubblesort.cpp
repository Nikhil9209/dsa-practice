#include<bits/stdc++.h>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i = n-1; i >=1 ; i--){  
         // n-1 se start karenge kyuki last element to apne aap sorted hoga aur har baar last element ko ignore krenge kyuki wo already sorted hai 
         int didswap = 0; // ye variable isliye use karenge ki agar kisi pass me swap nhi hua to iska value 0 hi rhega aur iska matlab hai ki array already sorted hai aur hume loop ko break kr dena chahiye taki time complexity O(n) ho jaye best case me
        for(int j = 0 ; j <=i-1 ; j++){ 
             // i-1 is liye kyuki apne ko last element ko ignore karna hai aur j+1 bhi access karna hai isliye i-1 tak loop chalega agr i -1 nhi krege to wo aise index ko access krne ki try krega jo available nhi h aur runtime error dega
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap = 1;
            }
        }
        if(didswap == 0){
            break;
        }
        // isse iski complexity O(n) ho jati hai best case me jab array already sorted hota hai kyuki us case me har pass me swap nhi hoga aur loop break ho jayega aur worst case me O(n^2) hi rhega jab array reverse sorted hota hai kyuki us case me har pass me swap hoga aur loop break nhi hoga
    }
}
int main(){
  int n ;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }

}