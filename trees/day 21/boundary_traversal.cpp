https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Given a root of a Binary Tree, return its boundary traversal in the following order:
    Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
    Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
    Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, 
                            excluding leaves, and added in reverse order.

Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows 
traversal preference not the path from the rightmost leaf.

/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> ans;
    int isLeaf(Node* root){
        return (root->left==NULL) && (root->right==NULL);
    }
    
    void leftSide(Node* root){
        Node* curr=root->left;
        while(curr){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    
    void leafnodes(Node* root){
        if(root==NULL) return;
        
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        
        leafnodes(root->left);
        leafnodes(root->right);
    }
    
    void rightSide(Node* root){
        Node* curr=root->right;
        vector<int> temp;
        
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(root==NULL) return ans;
        
        if(!isLeaf(root)) ans.push_back(root->data);
        
        leftSide(root);
        leafnodes(root);
        rightSide(root);
        return ans;
    }
};
