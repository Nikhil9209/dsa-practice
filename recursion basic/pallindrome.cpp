#include<bits/stdc++.h>
using namespace std;
void checkpallindrome(string name,int i , int n){
    if(name[i]!=name[n]){
        cout<<"not a pallindrome" ;
        return;
    }
    else if(i>=n){

        cout<<"is palllindrome";
        return  ;
    }
    checkpallindrome(name,i+1,n-1);
}
int main(){
    string name;
    cin>>name;
    checkpallindrome(name,0,name.length()-1);
    
}