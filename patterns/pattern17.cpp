#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        
        for(int k = 1; k < n - i; k++) {
            cout << " ";
        }

        char ch ='A';
        for(int l = 0; l <i; l++) {
            cout << ch;
            ch++;
        }
        if(i!=0){
            char ch = char('A'+i-2);
            for(int l = 1; l <i; l++) {
               cout <<ch;
               ch--;
                
        }
    }
        cout << endl;
    }
}