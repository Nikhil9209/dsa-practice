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

Node*insertatHead(Node*head,int val){
    Node*temp = new Node(val,head,nullptr);
    head->prev = temp;
    return head;
}
int main (){
    return 0 ;
}