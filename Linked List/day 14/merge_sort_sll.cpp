Merge Sort

class Solution {
public:

    // Step 1: Find middle of linked list
    Node* findMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;  // important for proper split

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Step 2: Merge two sorted lists
    Node* merge(Node* left, Node* right) {

        if (!left) return right;
        if (!right) return left;

        Node* result = NULL;

        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }

    // Step 3: Main merge sort function
    Node* mergeSort(Node* head) {

        if (head == NULL || head->next == NULL)
            return head;

        Node* mid = findMid(head);
        Node* rightHead = mid->next;
        mid->next = NULL;   // break the list

        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        return merge(left, right);
    }
};



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


Own Method


class Solution {
  public:
    pair<Node*,Node*> splitarr(Node* head){
        if(head==NULL || head->next==NULL) return { head, NULL };
        Node* fast=head;
        Node* slow=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* second=slow->next;
        slow->next=NULL;
        return { head, second };
    }
    Node* merge1(Node* head){
        //Node* t=head;
        if(head==NULL || head->next==NULL) return head;
        
        pair<Node*,Node*> pii=splitarr(head);
        Node* left=merge1(pii.first);
        Node* right=merge1(pii.second);
        
        vector<int> temp;
        Node* t1=left;
        //Node* res=t1;
        Node* t2=right;
        //int k=0,x=0,y=0;
        while(t1!=NULL && t2!=NULL){
            if(t1->data > t2->data){
                temp.push_back(t2->data);
                t2=t2->next;
            }
            else{
                temp.push_back(t1->data);
                t1=t1->next;
            }
        }
        while(t1!=NULL){
            temp.push_back(t1->data);
            t1=t1->next;
        }
        while(t2!=NULL){
            temp.push_back(t2->data);
            t2=t2->next;
        }
        /*Node* t=head;
        for(int i=0;i<temp.size();i++){
            t->data=temp[i];
            t=t->next;
        }
        return head;*/
        
        Node* dummy = new Node(0);
        Node* curr = dummy;
        
        Node* t11 = left;
        Node* t22 = right;
        
        while(t11 && t22){
            if(t11->data <= t22->data){
                curr->next = t11;
                t11 = t11->next;
            } else {
                curr->next = t22;
                t22 = t22->next;
            }
            curr = curr->next;
        }
        
        curr->next = (t11 ? t11 : t22);
        
        return dummy->next;
    }
    Node* mergeSort(Node* head) {
        // code here
        if(head==NULL || head->next==NULL) return head;
        
        return merge1(head);
        //return head;
    }
};
