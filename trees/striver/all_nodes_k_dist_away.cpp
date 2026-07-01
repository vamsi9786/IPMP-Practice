https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Idea: use hash map and store store parent for each node. 
      start BFS from target node and move to left right par and decrease dist by k--

Code: 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> par;
    void dfs(TreeNode* root){
        if(root==NULL) return;

        if(root->left){
            par[root->left]=root;
            dfs(root->left);
        }
        if(root->right){
            par[root->right]=root;
            dfs(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> arr;
        dfs(root);

        queue<TreeNode*> que;
        unordered_set<TreeNode*> vis;

        que.push(target);
        vis.insert(target);

        int dist=0;
        while(!que.empty()){
            if(dist==k) break;
            
            int n=que.size();
            for(int i=0;i<n;i++){
                TreeNode* node=que.front();
                que.pop();

                if(node->left && !vis.count(node->left)){
                    que.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    que.push(node->right);
                    vis.insert(node->right);
                }
                if(par[node] && !vis.count(par[node])){
                    que.push(par[node]);
                    vis.insert(par[node]);
                }
            }
            dist++;
        }

        vector<int> res;
        while(!que.empty()){
            res.push_back(que.front()->val);
            que.pop();
        }
        return res;
    }
};
