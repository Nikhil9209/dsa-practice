/*
    Problem: Remove Nth Node From End of List

    Topic: Linked List

    Pattern: Length Calculation + Two Traversals

    Brute Force:
    1. Traverse the linked list and calculate its length.
    2. The node to remove from the beginning is:
       length - n
    3. Traverse again to reach the node before the target.
    4. Delete the target node and adjust the links.

    Optimal Approach:
    The two-pointer approach can solve this in one traversal:
    - Move fast pointer n steps ahead.
    - Move slow and fast together.
    - When fast reaches the end, slow is at the node before
      the node that needs to be deleted.

    Your submitted solution uses the length + two traversal
    approach, which is correct.

    Time Complexity: O(n)
    Space Complexity: O(1)

    Key Learning:
    Nth node from end → find length → target position from start
    = length - n → reach previous node → delete target.

    Revision:
    One-pass optimal pattern = fast n steps ahead → move both
    → slow reaches node before the target.
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;

        // Empty list or only one node
        if(temp == nullptr || temp->next == nullptr) {
            return nullptr;
        }

        int count = 0;

        // Find length
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }

        temp = head;

        // If head itself needs to be removed
        if(count == n) {

            ListNode* del = head;
            head = head->next;

            delete del;

            return head;
        }

        // Position of node from the beginning
        int remove = count - n;
        count = 0;

        // Reach node before the target
        while(temp != nullptr) {

            count++;

            if(count == remove) {

                ListNode* del = temp->next;

                temp->next = temp->next->next;

                delete del;

                break;
            }

            temp = temp->next;
        }

        return head;
    }
};

int main() {
    return 0;
}