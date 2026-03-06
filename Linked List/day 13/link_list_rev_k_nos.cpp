https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list.
Note: If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node * t=head;
        if(head==NULL || k<=1) return head;
        int c=0;
        while(t!=NULL){
            t=t->next;c++;
        }
        t=head;
        Node *prevHead=NULL;
        Node *curr=head;
        Node *prev=NULL;
        Node *next=NULL;
        for(int i=0;i<(c+k-1)/k && curr!=NULL;i++){
            prev=NULL;
            Node* currHead=curr;
            int cnt=0;
            while(curr!=NULL && cnt<k){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                cnt++;
            }

            if(prevHead!=NULL) prevHead->next=prev;
            prevHead=currHead;
            if(i==0) t=prev;
        }
        return t;
    }
};
