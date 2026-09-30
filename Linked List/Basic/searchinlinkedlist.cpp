/*
    Problem: Search Key in a Linked List

    Topic: Linked List

    Pattern: Linked List Traversal

    Brute Force:
    Traverse the linked list and check every node's value
    until the key is found.

    Optimal Approach:
    1. Start from the head node.
    2. Traverse the linked list using a temporary pointer.
    3. At every node, compare temp->val with key.
    4. If equal, return true.
    5. If the entire list is traversed without finding the key,
       return false.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    Search in linked list → traverse node by node
    → compare current value with key → return true if found.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Definition of ListNode:

    class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int value) : val(value), next(nullptr) {}

        ~ListNode() {
            delete next;
        }
    };
*/

class Solution {
public:

    bool searchKey(ListNode* head, int key) {

        ListNode* temp = head;

        while(temp != nullptr) {

            if(temp->val == key) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }
};

int main() {
    return 0;
}