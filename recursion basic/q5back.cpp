#include<bits/stdc++.h>
using namespace std;
void num(int n ,int i){
    if(i>n){
        return;
    }
    num(n,i+1);
    cout<<i
;
}
int main(){
    int n ;
    cin>>n;
    num(n,1);

}