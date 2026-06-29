https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Algo: use dfs and for each node: dfs returns ( node+left or node+right or node ) to upper nodes(i.e. parent node)
      and also another possibility exists if both dfs of both left and right > =0 then max can be from (left to node to right) 

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
    int ans=INT_MIN;

    int dfs(TreeNode* root){
        if(root==NULL) return 0;

        int left=max(0,dfs(root->left)); // to avoid negative value path addition
        int right=max(0,dfs(root->right));

        ans=max(ans,left+right+root->val);

        return root->val+max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        ans=max(ans,dfs(root));
        return ans;
    }
};
