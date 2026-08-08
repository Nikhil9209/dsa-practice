#include<bits/stdc++.h>
using namespace std;
vector<int>leader(vector<int>arr,int n ){
    vector<int> ans;
    ans.push_back(arr[n-1]);
    for(int i =n-2 ; i>=0;i--){
        if(arr[i]>){
            ans.push_back(arr[i-1]);
            mpp[arr[i-1]]++;
        }
    }
    return ans ;

}
int main(){
    int n ;
    cin>>n ;
    vector<int>arr(n);
    for(int i =0 ;i<n ;i++){
        cin>>arr[i];
    }
   cout<< leader(arr,n);
    
}
