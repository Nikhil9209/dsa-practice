/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:

    int addHelper(ListNode*temp){
        if(temp == NULL) return 1;

        int carry = addHelper(temp->next);
        temp->val +=carry;

        if(temp->val<10) return 0;

        temp->val =0;
        return 1;
    }
    ListNode *addOne(ListNode *head) {

        int carry = addHelper(head);

        if(carry == 1){
            ListNode*newNode = new ListNode(1);
            newNode->next = head;
            head = newNode ;

        }
        return head ;

    }
};