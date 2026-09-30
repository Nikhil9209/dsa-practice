/*
    Problem: Insert Node at Tail of Linked List

    Topic: Linked List

    Pattern: Tail Insertion + Traversal

    Brute Force:
    Traverse the linked list to reach the last node and then
    attach the new node.
    Time Complexity: O(n)

    Optimal Approach:
    1. If the list is empty, create a new node and return it as head.
    2. Start from head.
    3. Traverse until temp->next == nullptr.
       This means temp is the last node.
    4. Create a new node with value X.
    5. Connect temp->next to the new node.
    6. Return head.

    Time Complexity: O(n)
    Space Complexity: O(1) extra space

    Key Learning:
    Insert at tail → reach last node
    → temp->next == nullptr → attach new node.
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

    ListNode* insertAtTail(ListNode* &head, int X) {

        // Empty list
        if(head == nullptr) {
            return new ListNode(X, nullptr);
        }

        ListNode* temp = head;

        // Reach the last node
        while(temp->next != nullptr) {
            temp = temp->next;
        }

        // Create and attach new node
        ListNode* ans = new ListNode(X, nullptr);
        temp->next = ans;

        return head;
    }
};

int main() {
    return 0;
}