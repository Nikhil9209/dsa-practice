/*
    Problem: Delete Node With Value X

    Topic: Linked List

    Pattern: Traversal + Previous Pointer

    Brute Force:
    Traverse the linked list and find the node whose data is X.
    Then delete that node by updating the previous node's next pointer.

    Optimal Approach:
    1. If the list is empty, return head.
    2. If the head itself contains X, delete the head.
    3. Use temp to traverse the list and prev to track
       the previous node.
    4. When temp->data == X:
       - Connect prev->next to temp->next.
       - Delete temp.
    5. Stop after deleting the first occurrence.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    Delete by value → handle head separately
    → traverse with temp + prev
    → prev->next = temp->next
    → delete temp.
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

    ListNode* deleteNodeWithValueX(ListNode* &head, int X) {

        // Empty list
        if(head == nullptr) {
            return head;
        }

        // If head contains X
        if(head->data == X) {
            ListNode* temp = head;
            head = temp->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr) {

            if(temp->data == X) {

                prev->next = temp->next;
                delete temp;
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};

int main() {
    return 0;
}