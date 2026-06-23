https://leetcode.com/problems/linked-list-cycle-ii/description/


Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Internally, pos is used to denote the index of the node that tail next pointer is connected to (0-indexed). 
It is -1 if there is no cycle. Note that pos is not passed as a parameter.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                ListNode* t1=head;
                ListNode* t2=slow;
                while(t1!=t2){
                    t1=t1->next;
                    t2=t2->next;
                }
                return t1;
            }
        }
        return NULL;
    }
};
