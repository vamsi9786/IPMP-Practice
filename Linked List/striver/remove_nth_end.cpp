https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Given the head of a linked list, remove the nth node from the end of the list and return its head

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1=head;
        ListNode* p2=head;
        for(int i=0;i<n;i++){
            p1=p1->next;
        }
        if(p1==NULL){
            return head->next;
        }
        while(p1->next!=NULL){
            p1=p1->next;
            p2=p2->next;
        }
        p2->next=p2->next->next;
        return head;
    }
};
