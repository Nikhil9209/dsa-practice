#include<bits/stdc++.h>
using namespace std;
void num(int n  ){
    if(n<1){
        return;
    }
    cout<<n;
    n--;
    num(n);
}
int main(){
    int n ;
    cin>>n;
    num(n);

}