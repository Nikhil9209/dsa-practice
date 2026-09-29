/*
    Problem: Linked List Traversal

    Topic: Linked List

    Pattern: Traversal using a Temporary Pointer

    Brute Force:
    Not applicable. We need to visit every node at least once.

    Optimal Approach:
    Start from the head node using a temporary pointer.
    Traverse the linked list until temp becomes nullptr.
    
    At every node:
    1. Store temp->data in the answer vector.
    2. Move temp to the next node using temp->next.

    Time Complexity: O(n)
    Space Complexity: O(n) for the answer vector

    Key Learning:
    Linked List traversal → start from head → process current node
    → move to next node → stop at nullptr.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Definition of singly linked list:

    class ListNode {
    public:
        int data;
        ListNode *next;

        ListNode() : data(0), next(nullptr) {}
        ListNode(int x) : data(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : data(x), next(next) {}
    };
*/

class Solution {
public:

    vector<int> LLTraversal(ListNode *head) {

        vector<int> ans;

        ListNode* temp = head;

        while(temp != nullptr) {

            ans.push_back(temp->data);

            temp = temp->next;
        }

        return ans;
    }
};

int main() {
    return 0;
}