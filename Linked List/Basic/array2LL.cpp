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

Node*convert2ll(vector<int>arr){

    Node*head  = new Node(arr[0]);
    Node*mover = head;

    for(int i = 1; i<arr.size();i++){

        Node* temp= new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }

    return head;


}

int main(){

    vector<int>arr ={2,5,6,15,2,55,5};

    Node*y = new Node(arr[0]);

    cout <<y;
}