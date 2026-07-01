https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

Idea: pass sum so far to children. if curr is leaf then add sum to overall sum

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
    int ans=0;
    void helper(TreeNode* root,int sum){
        if(root==NULL) return;
        sum=sum*10+(root->val);
        if(!root->left && !root->right){
            ans+=sum;
            return;
        }
        helper(root->left,sum);
        helper(root->right,sum);
    }

    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root,0);
        return ans;
    }
};
