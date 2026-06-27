https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and 
ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Algo: similar to hd (i.e horizontal dist) but use map<int,map<int,multiset<int>>> 2D Map

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<pair<TreeNode*,pair<int,int>>> que;
        map<int,map<int,multiset<int>>> mp;

        que.push({root,{0,0}});
        while(!que.empty()){
            auto it=que.front();
            que.pop();

            TreeNode* temp=it.first;
            auto pii=it.second;

            mp[pii.first][pii.second].insert(temp->val);

            if(temp->left) que.push({temp->left,{pii.first-1,pii.second+1}});
            if(temp->right) que.push({temp->right,{pii.first+1,pii.second+1}});
        }

        for(auto &it:mp){ //it stores key,value pair
            vector<int> temp;
            for(auto &y:it.second){
                for(int val: y.second){
                    temp.push_back(val);
                }
            }
            res.push_back(temp);
        }
        return res;

    }
};
