This line is safe:  mp[t]->next = mp[t->next];
Because:    
      In first pass, you already inserted all original nodes      
      So mp[t->next] will exist      
      If t->next == NULL, then mp[NULL] is accessed      
      ⚠ What happens here?        
          mp[NULL]: ===>  Inserts {NULL, NULL}   ====>  Returns NULL         
          So it works fine.

Use Hashmap of <Node* , Node*>

/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    void newnode(Node* head){
        
    }
    Node* cloneLinkedList(Node* head) {
        Node* t=head;
        if(head==NULL) return NULL;
        unordered_map<Node*,Node*> mp;
        while(t!=NULL){
            mp[t]=new Node(t->data);
            t=t->next;
        }
        t=head;
        while(t!=NULL){
            mp[t]->next=mp[t->next];
            mp[t]->random=mp[t->random];
            t=t->next;
        }
        return mp[head];
    }
};
