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

Node*beforeHead(Node*head,int val){
    Node*temp = new Node(val,nullptr,head);
    head->prev = temp;
    return temp;
}

Node*insertionbeforeNode(Node*head,int k,int val){
    if(k == 1)return beforeHead(head, val);
    Node*temp= head;
    int count = 0 ;

     while(temp!=nullptr){
        count++;
        if(count==k) break;

        temp = temp->next;
     }

        Node*back = temp->prev;

        Node*ans = new Node(val,back,temp);

        back->next = ans;

        temp->prev= ans ;


        return head;


     }
     

int main (){
    return 0 ;
}