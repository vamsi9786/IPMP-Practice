https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists

You are given the heads of two non-empty singly linked lists, head1 and head2, that intersect at a certain point. 
Return that Node where these two linked lists intersect.
Note: It is guaranteed that the intersected node always exists.
In the custom input you have to give input for CommonList which pointed at the end of both head1 and head2 to form a Y-shaped linked list.


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
    Node* intersectPoint(Node* head1, Node* head2) {
        unordered_set<Node*> mp;
        Node* t1=head1;
        while(t1!=NULL){
            mp.insert(t1);
            t1=t1->next;
        }
        Node* t2=head2;
        while(t2!=NULL){
            if(mp.find(t2)!=mp.end()){
                return t2;
            }
            t2=t2->next;
        }
        return NULL;
    }
};
