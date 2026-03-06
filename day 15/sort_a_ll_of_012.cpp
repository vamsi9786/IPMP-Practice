https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it

Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. 
Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Algorithm:
    1. Maintain head and tail for 0's 1's 2's
    2. while(curr!=NULL)
          if(val==0) 
              if(zeroH==NULL) zeroH=zeroT=curr
              else append it to zeroT i.e zeroT->next=curr and zeroT=curr
          else if(val==1)
              if(oneH==NULL) oneH=oneT=curr
              else append it to oneT i.e oneT->next=curr and oneT=curr
          else
              if(twoH==NULL) twoH=twoT=curr
              else append it to twoT i.e twoT->next=curr and twoT=curr
          curr=curr->next
      }
    3. if(zeroH) zeroT->next = oneH if exists else twoH
        if(oneH) oneT->next = twoH
        if(twoH) twoT->next = NULL;
    4. if(zeroH exists) return zeroH else ( if(oneH exists) return oneH else return twoH )

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zHead=NULL;
        Node* zTail=NULL;
        Node* oHead=NULL;
        Node* oTail=NULL;
        Node* tHead=NULL;
        Node* tTail=NULL;
        Node* curr=head;
        while(curr!=NULL){
            if(curr->data==0){
                if(zHead==NULL){
                    zHead=curr;
                    zTail=curr;
                }
                else{
                    zTail->next=curr;
                    zTail=curr;
                }
            }
            else if(curr->data==1){
                if(oHead==NULL){
                    oHead=curr;
                    oTail=curr;
                }
                else{
                    oTail->next=curr;
                    oTail=curr;
                }
            }
            else{
                if(tHead==NULL){
                    tHead=curr;
                    tTail=curr;
                }
                else{
                    tTail->next=curr;
                    tTail=curr;
                }
            }
            curr=curr->next;
        }
        if(zTail) zTail->next=(oHead)?oHead:tHead;
        if(oTail) oTail->next=tHead;
        if(tTail) tTail->next=NULL;
        
        return (zHead)?zHead:((oHead)?oHead:tHead);
    }
};

/*class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int c=1;
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
            c++;
        }
        
        Node* prev=NULL;
        Node* curr=head;
        Node* next=NULL;
        while(c--){
            next=curr->next;
            if(curr->data==0){ //add ele to start of ll
                if(prev!=NULL){
                    prev->next=next;
                    curr->next=head;
                    head=curr;
                }
            }
            else if(curr->data==2){ // add ele to tail of ll
                if(prev==NULL){
                    head=next;
                }
                else if(next==NULL){
                    tail=prev;
                }
                else{
                    prev->next=next;
                }
                tail->next=curr;
                tail=curr;
                tail->next=NULL;
            }
            else prev=curr;
            curr=next;
        }
        return head;
    }
};*/
