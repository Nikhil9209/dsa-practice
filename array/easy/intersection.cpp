#include<bits/stdc++.h>
using namespace std;
void intersection(int arr[],int arri[], int n , int m){
    vector<int> temp;
    for(int i =0;i<n;i++){
        temp.push_back(arr[i]);
    }
    for(int i =0;i<m;i++){
        temp.push_back(arri[i]);
    }
    sort(temp.begin(),temp.end());
    int i =0;
    for(int j =1;j<m+n;j++){
        if(temp[j]!=temp[i]){
            temp[i+1]=temp[j];
            i++;
        }
    }
    for(int k =0;k<i;k++){
        cout<< temp[i];
    }
    
}
int main(){
    int m ;
    int n ;
    cin>>m>>n;
    int arr[n];
    int arri[m];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
        for(int i =0;i<m;i++){
        cin>>arri[i];
    }
    intersection(arr,arri,n,m);

}