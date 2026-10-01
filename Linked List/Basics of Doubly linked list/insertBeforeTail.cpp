#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;


    public:

    Node(int data1,Node*prev1,Node*next1){
        data = data1;
        prev = prev1;
        next = next1;
        
        }

        



};

Node* insertBeforeTail(Node* head, int val){

    if(head->next == nullptr){
        Node* ap = new Node(val, nullptr, head);
        head->prev = ap;

        return ap;
    }

    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* back = temp->prev;

    Node* ans = new Node(val, back, temp);

    back->next = ans;
    temp->prev = ans;

    return head;
}

int main (){
    return 0 ;
}