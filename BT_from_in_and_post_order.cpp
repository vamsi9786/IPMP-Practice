https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and 
postorder is the postorder traversal of the same tree, construct and return the binary tree.

Idea: postorder: left-right-root
      on i-- from n-1 the root goes in order like root-right-left in original tree 
      (lets say: root=3 and l=1 r=4 then 4->l=6 4->r=7 postorder would be: 1 6 7 4 3 the idx and 
        order goes like (from n-1): root ,root->r ,root->r->r ,root->r->l ,root->l )
      inorder: left-right-root
  
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
    unordered_map<int,int> mp;  

    int postIdx;
    TreeNode* build(vector<int>& postorder,int st,int end){
        if(st>end) return NULL;

        TreeNode* root=new TreeNode(postorder[postIdx--]);

        int pos=mp[root->val];
        root->right=build(postorder,pos+1,end);
        root->left=build(postorder,st,pos-1);
        
        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        postIdx=postorder.size()-1;
        return build(postorder,0,inorder.size()-1);
    }
};
