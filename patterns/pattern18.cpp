#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    char ch =char('A'+n-1);
     for(int i=1;i<=n;i++){
        char b = ch-i;
        for(int j=1;j<=i;j++){
            b++;
            cout<<b;
            
        }
        cout<<endl;
    }
}