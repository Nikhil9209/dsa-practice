#include<bits/stdc++.h>
using namespace std;

struct Node{

    public:

        int data ;
        Node*next;

    public:
        Node(int Data1, Node *next1){
            data = Data1;
            next = next1;

        }

        public:

        Node(int data1){
            data = data1;
            next = nullptr;
        }


};



int main(){

    vector<int>arr ={2,5,6,15,2,55,5};

    Node*y = new Node(arr[0]);

    cout <<y;
}