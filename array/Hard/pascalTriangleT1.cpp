#include<bits/stdc++.h>
using namespace std;
int ncr(int r,int c){
    int res=1;
    for(int i =0;i<r;i++){
        res= res*(r-i);
        res=res/(i+1);
    }
    return res;
}
int main (){
    int r;
    cin>>r;
    int c;
    cin>>c;
    cout<<ncr(r-1,c-1);
    
}
