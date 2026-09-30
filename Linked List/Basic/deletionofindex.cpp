v=/*
    Problem: Delete Kth Node of a Linked List

    Topic: Linked List

    Pattern: Traversal + Previous Pointer

    Brute Force:
    Traverse the linked list and count the nodes.
    Once the kth node is found, delete it by changing
    the next pointer of the previous node.

    Optimal Approach:
    1. If the list is empty, return head.
    2. If k == 1, delete the head node.
    3. Use two pointers:
       - temp → current node
       - prev → previous node
    4. Traverse until count == k.
    5. Connect prev->next to temp->next.
    6. Delete temp.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    To delete kth node → keep track of current and previous
    → prev->next = temp->next → delete temp.
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

    ListNode* deleteKthNode(ListNode* &head, int k) {

        // Empty list
        if(head == nullptr) {
            return head;
        }

        // Delete head node
        if(k == 1) {
            ListNode* temp = head;
            head = temp->next;
            delete temp;
            return head;
        }

        int count = 0;
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr) {

            count++;

            if(count == k) {
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