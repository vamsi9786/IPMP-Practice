https://leetcode.com/problems/binary-tree-level-order-traversal/description/

Level order  traversal:

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> que;
        vector<vector<int>> res;
        que.push(root);
        while(!que.empty()){
            int n=que.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* node=que.front();
                que.pop();
                level.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
