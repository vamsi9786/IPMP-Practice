https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:
          Choose any node in the binary tree and a direction (right or left).
          If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
          Change the direction from right to left or from left to right.
          Repeat the second and third steps until you cant move in the tree.
          Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Method-1:
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

    void dfs(TreeNode* root,int leftLen,int rightLen){
        if(root==NULL) return;

        ans=max(ans,max(leftLen,rightLen));

        // Move left -> previous move becomes left,
        // so continue only if previous move was right.
        dfs(root->left,rightLen+1,0);

        // Move right -> previous move becomes right,
        // so continue only if previous move was left.
        dfs(root->right,0,leftLen+1);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root,0,0);
        return ans;
    }
};

My Method:
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
    //flag used for curr direction
    //flag denotes left for true and right for false
    int ans=0;
    int helper(TreeNode* root,bool flag){
        if(root==NULL) return 0;
        int right=helper(root->right,!flag);
        int left=helper(root->left,!flag);
        ans=max(ans,max(left,right));
        if(flag) return 1+right;
        else return 1+leftt;
    }

    int longestZigZag(TreeNode* root) {
        if(root==NULL) return 0;
        ans=max(ans,helper(root,true));
        ans=max(ans,helper(root,false));
        return ans-1;
    }
};
