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
int main (){
    return 0 ;
}