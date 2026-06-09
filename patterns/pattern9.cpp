#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {

        for(int k = 1; k < n - i; k++) {
            cout << " ";
        }

        
        for(int l = 0; l < 2*i + 1; l++) {
            cout << "*";
        }

        cout << endl;
    
    }
    for(int i =1;i<=n;i++){
        for(int j =1; j<i;j++){
            cout<<" ";
        }
        for(int k =0;k<2*n-2*i+1;k++){
            cout<<"*";
        }
        cout<<endl;
    }

}