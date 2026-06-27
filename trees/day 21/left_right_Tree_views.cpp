
1. Binary Tree Right Side View
code: 
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
    vector<int> res;
    void helper(TreeNode* root,int depth){
        if(root==NULL) return;
        if(depth==res.size()){
            res.push_back(root->val);
        }
        helper(root->right,depth+1);
        helper(root->left,depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        helper(root,0);
        return res;
    }
};

2. Binary Tree Left Side View
Code:
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> res;
    
    void helper(Node* root,int depth){
        if(root==NULL) return;
        
        if(res.size()==depth) res.push_back(root->data);
        
        helper(root->left,depth+1);
        helper(root->right,depth+1);
    }
    
    vector<int> leftView(Node *root) {
        // code here
        helper(root,0);
        return res;
    }
};
