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


2. Reverse level order

/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> res;
        if(root==NULL) return res;
        
        queue<Node*> que;
        que.push(root);
        
        stack<int> stk;
        
        while(!que.empty()){
            Node* node=que.front();
            que.pop();
            
            stk.push(node->data);  // or use res.insert(res.begin(),node->data) but it takes O(n2)
            
            if(node->right) que.push(node->right);
            if(node->left) que.push(node->left);
        }
        
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
