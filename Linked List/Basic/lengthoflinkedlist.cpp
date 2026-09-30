/*
    Problem: Find Length of a Linked List

    Topic: Linked List

    Pattern: Linked List Traversal

    Brute Force:
    Traverse the linked list and count every node.
    There is no better approach because every node needs to be visited.

    Optimal Approach:
    1. Start from the head using a temporary pointer.
    2. Initialize count = 0.
    3. Traverse until temp becomes nullptr.
    4. Increment count for every node.
    5. Move temp to the next node.
    6. Return count.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    Length of linked list → traverse from head to nullptr
    → increment count for every node.
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

    int getLength(ListNode* head) {

        ListNode* temp = head;
        int count = 0;

        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main() {
    return 0;
}