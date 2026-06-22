You are given the head of a linked list, You have to return the value of the middle node of the linked list.

If the number of nodes is odd, return the middle node value.
If the number of nodes is even, there are two middle nodes, so return the second middle node value.

/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        // code here
        Node* fast=head;
        Node* slow=head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow->data;
    }
};

class Solution {
  public:
    int getMiddle(Node* head) {
        int n=0;
        Node* t=head;
        while(t!=NULL){
            n++;
            t=t->next;
        }
        int req=(n%2==0)?(n+2)/2:(n+1)/2;
        int res;
        t=head;
        while(req--){
            res=t->data;
            t=t->next;
        }
        return res;
    }
};
