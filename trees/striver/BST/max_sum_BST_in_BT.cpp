https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:          
          The left subtree of a node contains only nodes with keys less than the node's key.
          The right subtree of a node contains only nodes with keys greater than the node's key.
          Both the left and right subtrees must also be binary search trees.

Idea: For every subtree, determine whether it is a BST. If it is, compute its sum and update the global answer.
      This is a postorder DFS because a node can be classified as a BST only after knowing information about its left and right subtrees.

      For every subtree, DFS return 4 values:
                                isBST → Is this subtree a BST?
                                minValue → Needed by the parent to validate BST property.
                                maxValue → Needed by the parent to validate BST property.
                                sum → Sum of this BST.
      BST Condition: ( left.isBST && right.isBST && left.max < root->val && root->val < right.min )
  
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
    struct info{
        bool isBST;
        int minVal,maxVal,sum;
    };

    int ans=0;
    info dfs(TreeNode* root){
        if(!root) return {true,INT_MAX,INT_MIN,0};

        info left=dfs(root->left);
        info right=dfs(root->right);

        if(left.isBST && right.isBST && root->val>left.maxVal && root->val<right.minVal){
            int curr=left.sum+right.sum+root->val;
            ans=max(ans,max(0,curr));
            
            return{
                true,
                min(left.minVal,root->val),
                max(root->val,right.maxVal),
                curr
            };
        }

        return { false,0,0,0 };
    }

    int maxSumBST(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root);

        return ans;
    }
};
