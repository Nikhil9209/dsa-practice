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


Node*Deletenode(Node*head,Node*temp){

    Node*front = temp->next;
    Node*back = temp->prev;

    if(front== nullptr){

        back->next = nullptr;
        delete temp;
        return head;
        
    }

    if(back == nullptr){
        head = temp->next;

        head->prev = nullptr;
        return head;
        delete temp;
    }


    back->next= front;

    front->prev = back;
    delete temp;
    return head;

}
int main (){
    return 0 ;
}