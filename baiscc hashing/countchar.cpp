#include<bits/stdc++.h>
using namespace std;
int main(){
    string name;
    cin>>name;
    int arr[26]={0};
    for(int i =0;i<26;i++){
        arr[name[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q--){
        char alpha;
        cin>>alpha;
        cout<<arr[alpha-'a']<<endl;
        
    }
}