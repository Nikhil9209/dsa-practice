#include<bits/stdc++.h>
using namespace std;
void num(int i ,int n){
    if(i<1){
        return;
    }
    num(i-1,n);
    cout<<i;

}
int main(){
    int n;
    cin>>n;
    num(n,n);

}
