https://leetcode.com/problems/maximum-width-of-binary-tree/description/

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes 
between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

Idea: Use heap like allocation for BT i.e  store root: i and left: 2*i+1 and right: 2*i+2
      Perform BFS

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        long long ans=0;

        queue<pair<TreeNode*,long long>> que;
        que.push({root,0});

        while(!que.empty()){
            int n=que.size();
            int minIdx=que.front().second;
            long long st,end;

            for(int i=0;i<n;i++){
                auto it=que.front();
                que.pop();

                TreeNode* node=it.first;
                long long curr=it.second-minIdx; //Normalize the idx

                if(i==0) st=curr;
                if(i==n-1) end=curr;

                if(node->left) que.push({node->left,2*curr+1});
                if(node->right) que.push({node->right,2*curr+2});
            }
            ans=max(ans,end-st+1);
        }
        return (int)ans;
    }
};
