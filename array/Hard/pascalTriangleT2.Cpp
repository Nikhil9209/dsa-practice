
#include<bits/stdc++.h>
using namespace std;
void printRow(int r){
    int ans =1;
    for(int i =1;i<r;i++){
        ans= ans*(r-i);
        ans = ans/(i);
        cout<<ans;
    }
}
int main (){
    int r;
    cin>>r;
    int c;
    cin>>c;
    printRow(5);
}
