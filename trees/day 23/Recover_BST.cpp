https://leetcode.com/problems/recover-binary-search-tree/description/

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.

Idea: in Inorder either 1 swap is req or 2 swap is req i.e either 1 or 2 violations happens if 2 nodes are swpped in BST
      so store first violation and middle also

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
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;
    TreeNode* prev=NULL;

    void inorder(TreeNode* root){
        if(root==NULL) return;

        inorder(root->left);

        if(prev && prev->val > root->val){
            if(!first){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if(last){
            swap(last->val,first->val);
        }
        else{
            swap(middle->val,first->val);
        }
        return;
    }
};
