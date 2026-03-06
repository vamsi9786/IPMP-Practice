https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

Given a linked list containing n head nodes where every node in the linked list contains two pointers:
    (i) next points to the next node in the list.
    (ii) bottom points to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. 
Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Algorithm:
      1. if(root==NULL || root->next==NULL) return root;
      2. recurrsively flatten root->next
           i.e  root->next=flatten(root->next);
      3. merge root and root->next recurrsively like merge sort helper fn
          Merge(Node* a, Node* b) :
              if(!a) return a or if(!b) return b
              if(a->data < b->data) res=a; res->bottom=merge(a->bottom,b);
              else res=b; res->bottom=merge(a,b->bottom);
              res->next=NULL;
      4. return root

/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* a,Node* b){
        if(!a) return b;
        if(!b) return a;
        Node* res;
        if(a->data < b->data){
            res=a;
            res->bottom=merge(a->bottom,b);
        }
        else{
            res=b;
            res->bottom=merge(a,b->bottom);
        }
        res->next=NULL;
        return res;
    }
    Node *flatten(Node *root) {
        if(root==NULL || root->next==NULL) return root;
        
        root->next=flatten(root->next);
        root=merge(root,root->next);
        return root;
    }
};
