https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1

Given a root binary tree (BT), the task is to convert this to a Circular Doubly Linked List (CDLL) in-place. 
The left and right pointers in nodes will be used as previous and next pointers respectively in CDLL. 
The order of nodes in CDLL must be the same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the CDLL.

Idea: During inorder we simply connect left->root->right

Interview Expected: uses O(1) memory not recursive stack

/*class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/


class Solution {
  public:
    Node* prev=NULL;
    Node* head=NULL;
    
    void inorder(Node* root){
        if(root==NULL) return;
        
        inorder(root->left);
        if(prev==NULL){
            head=root;
        }
        else{
            prev->right=root;
            root->left=prev;
        }
        
        prev=root;
        
        inorder(root->right);
    }
    
    Node *bTreeToCList(Node *root) {
        // code here.
        if(root==NULL) return NULL;
        
        inorder(root);
        
        head->left=prev;
        prev->right=head;
        
        return head;
    } 
};


My Approach: return head and tail for each LL (uses recursive stack for memory)

/*class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    
    pair<Node*,Node*> helper(Node* root){
        if(root==NULL) return {NULL,NULL};
        
        auto left=helper(root->left);
        
        if(left.second){
            left.second->right=root;
            root->left=left.second;
        }
        
        auto right=helper(root->right);
        if(right.first){
            root->right=right.first;
            right.first->left=root;
        }
        
        Node* temp1=(left.first)?left.first:root;
        Node* temp2=(right.second)?right.second:root;
        return {temp1,temp2};
    }
    
    Node *bTreeToCList(Node *root) {
        // code here.
        if(root==NULL) return NULL;
        auto p=helper(root);
        p.first->left=p.second;
        p.second->right=p.first;
        return p.first;

    } 
};
