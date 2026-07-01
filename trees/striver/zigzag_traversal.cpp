https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

Given the root of a binary tree, return the zigzag level order traversal of its nodes values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Idea: have a bool flag for left_To_Right if L_R then true if R_L then false.
      if(!flag) reverse the level

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int d=0;
        vector<vector<int>> res;
        if(root==NULL) return res;

        queue<TreeNode*> que;
        que.push(root);

        bool flag=true; //for left to right

        while(!que.empty()){
            int n=que.size();
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                TreeNode* node=que.front();
                que.pop();

                //int idx=(flag)?i:n-1-i;
                //temp[idx]=node->val;

                temp[i]=node->val; //final reverse approach

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            if(!flag) reverse(temp.begin(),temp.end()); //reverse level approach
            res.push_back(temp);
            flag=!flag;
        }

        return res;
    }
};
