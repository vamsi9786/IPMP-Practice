https://leetcode.com/problems/delete-node-in-a-bst/description/

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
          Search for a node to remove.
          If the node is found, delete the node.

Algo: 1. If no child ==> delete node
      2. If single child ==> make it node
      3. If both child ==> find inorder successor and replace its val with node->val
                            and recursively delete inorder successor

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findMin(TreeNode* root){
        while(root->left) root=root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key < root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            TreeNode* succ=findMin(root->right); //inorder successor
            root->val=succ->val;
            root->right=deleteNode(root->right,succ->val);
        }
        return root;
    }
};
