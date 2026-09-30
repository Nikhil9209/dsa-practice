/*
    Problem: Insert Node at Kth Position

    Topic: Linked List

    Pattern: Traversal + Pointer Manipulation

    Brute Force:
    Traverse the linked list until reaching the (K-1)th node,
    then insert the new node.

    Optimal Approach:
    1. If the list is empty, create the new node.
    2. If K == 1, insert the new node at the head.
    3. Start from the head and keep a count.
    4. Reach the (K-1)th node.
    5. Create a new node and connect it between temp
       and temp->next.
    6. Return head.

    Time Complexity: O(n)
    Space Complexity: O(1) extra space

    Key Learning:
    Insert at Kth position →
    reach (K-1)th node →
    newNode->next = temp->next →
    temp->next = newNode.
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

    ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {

        if(head == nullptr) {
            return new ListNode(X, head);
        }

        if(K == 1) {
            return new ListNode(X, head);
        }

        int count = 1;
        ListNode* temp = head;

        while(temp != nullptr) {

            if(count == K - 1) {

                ListNode* ans = new ListNode(X, temp->next);
                temp->next = ans;

                break;
            }

            count++;
            temp = temp->next;
        }

        return head;
    }
};

int main() {
    return 0;
}