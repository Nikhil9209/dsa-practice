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
int main (){
    return 0 ;
}