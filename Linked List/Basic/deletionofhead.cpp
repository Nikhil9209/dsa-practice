/*
Definition of singly linked list:
class ListNode{
  
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/
#include<bits/stdc++.h>
class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        //your code goes here
        ListNode*temp=head;
        head = temp->next;
        delete temp;

        return head;
    }


};

int main(){
    return 0;
}