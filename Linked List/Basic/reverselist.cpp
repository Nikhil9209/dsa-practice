/*
    Problem: Reverse Linked List

    Topic: Linked List

    Pattern: Iterative Pointer Reversal

    Brute Force:
    Store all node values in another data structure and create
    a reversed linked list.
    This requires O(n) extra space.

    Optimal Approach:
    Use three pointers:
    - pre     → previous node
    - current → current node
    - temp    → next node

    For every node:
    1. Store current->next in temp.
    2. Reverse the current node's pointer:
       current->next = pre
    3. Move pre to current.
    4. Move current to temp.
    5. Continue until current becomes nullptr.

    At the end, pre points to the new head.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    Reverse LL → save next → reverse pointer
    → move pre and current forward.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Definition for singly-linked list:

    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
*/

class Solution {
public:

    ListNode* reverseList(ListNode* head) {

        ListNode* pre = nullptr;
        ListNode* current = head;

        while(current != nullptr) {

            // Save next node
            ListNode* temp = current->next;

            // Reverse current node's pointer
            current->next = pre;

            // Move pre forward
            pre = current;

            // Move current forward
            current = temp;
        }

        return pre;
    }
};

int main() {
    return 0;
}