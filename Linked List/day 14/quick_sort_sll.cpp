
Algorithm:
    1. if t->data > pivot->data then remove t and add to end i.e next of tail
        else none
    2. recurrsively sort(left ) and sort(right)
        by finding new head and new tail and 
                sort(newHead,pivot) and 
                link tail(newHead)->next as pivot and
                pivot->next=sort(pivot->next,newTail).

class Solution {
public:

    Node* getTail(Node* cur) {
        while (cur != NULL && cur->next != NULL)
            cur = cur->next;
        return cur;
    }

    Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {

        Node* pivot = end;
        Node* prev = NULL;
        Node* cur = head;
        Node* tail = pivot;

        while (cur != pivot) {

            if (cur->data < pivot->data) {

                if (*newHead == NULL)
                    *newHead = cur;

                prev = cur;
                cur = cur->next;
            }

            else {

                if (prev)
                    prev->next = cur->next;

                Node* temp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = temp;
            }
        }

        if (*newHead == NULL)
            *newHead = pivot;

        *newEnd = tail;

        return pivot;
    }

    Node* quickSortRecur(Node* head, Node* end) {

        if (!head || head == end)
            return head;

        Node* newHead = NULL;
        Node* newEnd = NULL;

        Node* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {

            Node* temp = newHead;

            while (temp->next != pivot)
                temp = temp->next;

            temp->next = NULL;

            newHead = quickSortRecur(newHead, temp);

            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    Node* quickSort(Node* head) {
        Node* tail = getTail(head);
        return quickSortRecur(head, tail);
    }
};

Quick sort by swapping values(may be bubble+pivot)

step 1: find tail(head) and while(t!=tail) swap data values if(t->data > pivot(i.e tail)->data) and
        prev of(pivot) ==> prev->next=NULL and res=t and res->t = sort(head) and return res
Step 2: in main sort fn (not helper sort fn i.e recurrsive) 
        reverse(res);

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */
// Solution class with quickSort function
class Solution {
  public:
    void swapNodes(struct Node* t1,struct Node* t2){
        int temp=t1->data;
        t1->data=t2->data;
        t2->data=temp;
    }
    struct Node* findtail(struct Node* t){
        while(t!=NULL && t->next!=NULL){
            t=t->next;
        }
        return t;
    }
    struct Node* reversal(struct Node* head){
        struct Node* prev=NULL;
        struct Node* curr=head;
        struct Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    struct Node* quick1(struct Node* head){
        if(head==NULL || head->next==NULL) return head;
        struct Node* tail=findtail(head);
        struct Node* t=head;
        struct Node* prev=NULL;
        while(t!=NULL && t!=tail){
            if(t->data >= tail->data){
                swapNodes(t,tail);
            }
            prev=t;
            t=t->next;
        }
        struct Node* res=t;
        prev->next=NULL;
        res->next=quick1(head);
        return res;
    }
    struct Node* quickSort(struct Node* head) {
        if(head==NULL || head->next==NULL) return head;
        struct Node* res=quick1(head);
        return reversal(res);
    }
};
