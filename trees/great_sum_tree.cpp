https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is 
changed to the original key plus the sum of all keys greater than the original key in BST.

Idea: Use reverse inorder

1. Better approach: reverse inorder
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:
    int sum = 0;

    void reverseInorder(TreeNode* root) {
        if (root == nullptr)
            return;

        reverseInorder(root->right);

        sum += root->val;
        root->val = sum;

        reverseInorder(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};



2. Mine: not better

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
    void inorder(vector<int>& res,unordered_map<int,TreeNode*>& mp,TreeNode* root){
        if(root==NULL) return;
        inorder(res,mp,root->left);
        res.push_back(root->val);
        mp[root->val]=root;
        inorder(res,mp,root->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        unordered_map<int,TreeNode*> mp;

        vector<int> in;
        inorder(in,mp,root);

        int n=in.size();
        vector<int> suf(n+1);
        suf[n]=0;
        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1]+in[i];
        }

        for(int i=0;i<n;i++){
            TreeNode* temp=mp[in[i]];
            temp->val=suf[i];
        }
        return root;
    }
};
