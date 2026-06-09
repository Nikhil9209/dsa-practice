#include<bits/stdc++.h>
using namespace std;
int num(int n ){
    if(n==0||n==1){
        return 1;
    }
    return( n * num(n-1));
}
int main(){
    int n ;
    cin>>n;
    cout<<num(n);
}