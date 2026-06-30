https://www.geeksforgeeks.org/problems/clone-a-binary-tree/1

A special binary tree with random pointers along with the usual left and right pointers is given. Clone the given tree.
Note: The output is 1 if the tree is cloned successfully. Otherwise, the output is 0.

Idea: Use hash map and store all nodes

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution {
  public:
    /* The function should clone the passed tree and return
       root of the cloned tree */
    unordered_map<Node*,Node*> mp;
    
    void helper(Node* root){
        if(root==NULL) return;
        Node* temp=new Node(root->data);
        mp[root]=temp;
        helper(root->left);
        helper(root->right);
    }
    
    void helper2(Node* root){
        if(root==NULL) return;
        mp[root]->left=(mp[root->left])?mp[root->left]:NULL;
        mp[root]->right=(mp[root->right])?mp[root->right]:NULL;
        mp[root]->random=(mp[root->random])?mp[root->random]:NULL;
        helper2(root->left);
        helper2(root->right);
    }
    
    Node* cloneTree(Node* root) {
        // Your code here
        helper(root);
        helper2(root);
        return (mp[root])?mp[root]:NULL;
    }
};
