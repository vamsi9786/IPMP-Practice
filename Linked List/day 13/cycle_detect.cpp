Floyd's Cycle Detection
using fast and slow pointer

algorithm
        ==>Why do they meet..?
                Inside a loop:          
                    Fast is moving 1 node faster than slow            
                    That means the distance between them keeps reducing   (if cycle exists)   
                    Eventually → distance becomes 0

bool detectLoop(Node* head) {
    if (head == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

alternate
using hash map i.e unorrdered set
/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        if(head==NULL || head->next==NULL) return false;
        unordered_set<Node*> vis;
        Node* t=head;
        while(t!=NULL){
            if(vis.find(t)!=vis.end()) return true;
            vis.insert(t);
            t=t->next;
        }
        return false;
    }
};
