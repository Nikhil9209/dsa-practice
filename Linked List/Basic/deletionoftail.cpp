/*
    Problem: Delete Tail of Linked List

    Topic: Linked List

    Pattern: Linked List Traversal + Pointer Manipulation

    Brute Force:
    Traverse the entire linked list and store the nodes.
    Then delete the last node.
    This uses extra O(n) space.

    Optimal Approach:
    1. If the list is empty, return nullptr.
    2. If there is only one node, delete it and return nullptr.
    3. Traverse until temp->next->next becomes nullptr.
       This means temp is the second-last node.
    4. Delete temp->next (the tail node).
    5. Set temp->next = nullptr.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    To delete the tail → reach the second-last node
    → delete temp->next → set temp->next = nullptr.
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

    ListNode* deleteTail(ListNode* &head) {

        // Empty list
        if(head == nullptr) {
            return nullptr;
        }

        // Only one node
        if(head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* temp = head;

        // Reach second-last node
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }

        // Delete last node
        delete temp->next;

        // Make second-last node the new tail
        temp->next = nullptr;

        return head;
    }
};

int main() {
    return 0;
}