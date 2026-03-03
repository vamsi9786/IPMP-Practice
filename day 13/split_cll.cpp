class Solution {
  public:
    pair<Node*, Node*> splitList(Node* head) {
        
        if (head == NULL)
            return {NULL, NULL};

        if (head->next == head)
            return {head, NULL};

        Node* slow = head;
        Node* fast = head;

        // move fast by 2 and slow by 1
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // For even number of nodes
        if (fast->next->next == head)
            fast = fast->next;

        Node* head1 = head;
        Node* head2 = slow->next;

        // make first half circular
        slow->next = head1;

        // make second half circular
        fast->next = head2;

        return {head1, head2};
    }
};




/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        // code here
        Node* fast=head;
        Node* slow=head;
        
        if(head->next->next==head){
            Node* head2=head->next;
            head2->next=head2;
            head->next=head;
            return { head, head2 };
        }
        Node* prev=NULL;
        slow=head->next;
        Node* fprev=NULL;
        fast=head->next->next;
        
        while(fast!=head && fast->next!=head){
            fprev=fast->next;
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(fast==head){
            prev->next=head;
            fprev->next=slow;
            return { head, slow };
        }
        else if(fast->next==head){
            Node* t=slow->next;
            slow->next=head;
            fast->next=t;
            return { head, t };
        }
    }
};
