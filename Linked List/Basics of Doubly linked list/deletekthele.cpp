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

Node*DeleteHead(Node*head){
    if(head == nullptr || head ->next == nullptr) return nullptr;
    Node*prev = head;
    head = head->next;
    head->prev = nullptr;
    delete prev;
    return head;

}
Node*Delettail(Node*head){
    if(head == nullptr || head ->next == nullptr) return nullptr;
    Node*temp = head;
    while(temp->next!= nullptr){
        temp = temp->next;
    }
    Node*ans = temp->prev;
    ans->next = nullptr;
    delete temp;
    return head;

}


Node*deletek(Node*head,int k ){
    Node*temp= head ; 
    int count = 0;

    while(temp!= nullptr){

        count++;

        if(k== count) break;;

        temp = temp->next;

    }

    Node*back = temp->prev;

    Node*front = temp->next;


    if(back==nullptr && front ==nullptr){ delete temp;

        return nullptr;
    }

    if(front== nullptr) return Delettail(head);

    if(back==nullptr) return DeleteHead(head);


    back->next = front;

    front->prev = back;

    delete temp;
    return head;
}
int main (){
    return 0 ;
}