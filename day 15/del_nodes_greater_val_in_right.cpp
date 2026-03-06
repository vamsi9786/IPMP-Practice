https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. 
Return the head of the modified linked list.

Algorithm:
    using recurrsion:
          1. if last node (head->next==NULL || head==NULL) return head
          2. head->next = compute(head->next)
          3. if(head->next->data > head->data)
                    second=head->next;
                    head->next=NULL;
                    return second;
              else retrun head;
        
/*
The structure of linked list is the following

struct Node
{
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
    Node *compute(Node *head) {
        if(head==NULL || head->next==NULL) return head;
        head->next=compute(head->next);
        if(head->next->data > head->data){
            Node* second=head->next;
            head->next=NULL;
            return second;
        }
        else return head;
    }
};
