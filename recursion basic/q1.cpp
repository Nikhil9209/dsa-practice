#include<bits/stdc++.h>
using namespace std;

int cnt = 1;

void name() {
    if(cnt>5) {
        return;
    }

    cout << "nikhil" << endl;
    cnt++;
    name();
}

int main() {
    name();
}