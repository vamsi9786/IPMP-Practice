Find Pairs with Given Sum in Doubly Linked List

Given the head of a sorted doubly linked list of positive distinct integers, and a target integer, 
return a 2D array containing all unique pairs of nodes (a, b) such that a + b == target.

Each pair should be returned as a 2-element array [a, b] with a < b. The list is sorted in ascending order. 
If there are no such pairs, return an empty list.

/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        // Your code goes here
        vector<vector<int>> res;
        if(head==NULL || head->next==NULL) return res;

        ListNode* tail=head;
        while(tail!=NULL && tail->next!=head){
            tail=tail->next;
        }
        ListNode* left=head;
        ListNode* right=tail;

        while(left!=NULL && right!=NULL && left->val < right->val){
            int sum=(left->val)+(right->val);
            if(sum==target){
                vector<int> temp(2);
                temp[0]=left->val;
                temp[1]=right->val;
                res.push_back(temp);
                left=left->next;
                right=right->next;
            }
            else if(sum<target){
                left=left->next;
            }
            else right=right->prev;
        }
        return res;
    }
};
