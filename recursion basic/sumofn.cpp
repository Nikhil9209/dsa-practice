#include<bits/stdc++.h>
using namespace std;
void sumn(int n,int i){
    if(n<1){
        cout<<i;
        return ;
    }
    
    sumn(n-1,i+n);
}
int main(){
    int n;
    cin>>n;
    sumn(n,0);
    

}