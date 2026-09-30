/*
    Problem: Insert Node at Head of Linked List

    Topic: Linked List

    Pattern: Head Insertion

    Brute Force:
    Create a new node and traverse the linked list to find the
    position where it should be inserted.
    This is unnecessary for head insertion.

    Optimal Approach:
    1. Create a new node with value X.
    2. Make the new node point to the current head.
    3. Return the new node as the new head.

    Time Complexity: O(1)
    Space Complexity: O(1) extra space
                     (O(1) for the newly created node)

    Key Learning:
    Insert at head → new node's next = head
    → new node becomes the new head.
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

    ListNode* insertAtHead(ListNode* &head, int X) {

        ListNode* temp = new ListNode(X, head);

        return temp;
    }
};

int main() {
    return 0;
}