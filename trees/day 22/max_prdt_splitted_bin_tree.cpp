https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.

Idea: Compute each subtree sum and for each subtree: calc ans=max(ans,sub*(total-sub))

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
    long long sum=0;
    long long ans=0;
    
    long long findSum(TreeNode* root){
        if(!root) return 0;
        return root->val+findSum(root->left)+findSum(root->right);
    }

    long long dfs(TreeNode* root){
        if(!root) return 0;

        long long left=dfs(root->left);
        long long right=dfs(root->right);
        long long subtree=left+right+root->val;

        ans=max(ans,subtree*(sum-subtree));
        return subtree;
    }

    int maxProduct(TreeNode* root) {
        sum=findSum(root);
        int mod=1e9+7;
        dfs(root);

        return (int)(ans%mod);
    }
};
