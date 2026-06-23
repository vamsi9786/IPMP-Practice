https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

You are given the head of two singly linked lists head1 and head2 representing two non-negative integers. 
You have to return the head of the linked list representing the sum of these two numbers.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Algorithm:
      1. find no of digits in both no's using ll count
      2. if(c1 > c2 ) then add leading zeroes to head2(i.e no.2) untill c1==c2;
                while(c1>c2): 
                    Node* temp=new Node(0);
                    temp->next=head2;
                    head2=temp;
                    c2++;
          else if(c1 < c2 ) do similarly for head1(i.e no.1)
      3. add each digit recurrsively and modify carry(c)
                    add_dig(Node* h1,Node* h2):
                          if(!h1 && !h2) return NULL;
                          Node* next=add_dig(h1->next,h2->next);
                          sum = h1->next + h2->next + carry(c);
                          Node* res=new Node(sum%10);
                          res->next=next;
                          c=sum/10;
                          return res
      4. ans=add_dig(h1,h2);
      5. if(c) then add new Node(c) and add it before ans ; ans=newAns; return ans;
      6. remove leading zeroes if exists and return ans;

Code-

/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int c=0;
    Node* helper(Node* h1,Node* h2){
        if(!h1 && !h2){
            return NULL;
        }
        Node* next=helper(h1->next,h2->next);
        int sum=h1->data+h2->data+c;
        
        Node* res=new Node(sum%10);
        res->next=next;
        
        c=sum/10;
        return res;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        int c1=0,c2=0;
        Node* t=head1;
        while(t!=NULL){
            t=t->next;
            c1++;
        }
        t=head2;
        while(t!=NULL){
            c2++;
            t=t->next;
        }
        while(c1<c2){
            Node* temp=new Node(0);
            temp->next=head1;
            head1=temp;
            c1++;
        }
        while(c1>c2){
            Node* temp=new Node(0);
            temp->next=head2;
            head2=temp;
            c2++;
        }
        Node* ans=helper(head1,head2);
        
        if(c){
            Node* temp= new Node(c);
            temp->next=ans;
            ans=temp;
            return ans;
        }
        while(ans && ans->data==0){
            ans=ans->next;
        }
        return ans;
    }
};
