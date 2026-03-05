Algorithm:
      1. split the ll into 2 parts
      2. reverse the ll of 2nd part
      3. while(t2!=NULL) if each t1's data matches t2's data it is palindrome else false;

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    pair<Node*,Node*> splitll(Node* head){
        if(head==NULL || head->next==NULL) return { head, NULL };
        Node* fast=head;
        Node* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node* second=slow->next;
        slow->next=NULL;
        return { head ,second };
    }
    Node* reversal(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(Node *head) {
        if(head->next==NULL) return true;

        pair<Node*,Node*> pii=splitll(head);
        Node* t1=pii.first;
        Node* t2=pii.second;
        t2=reversal(t2);
        while(t2!=NULL){
            if(t1->data!=t2->data){
                return false;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return true;
    }
};
