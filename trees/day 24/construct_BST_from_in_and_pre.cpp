https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and 
inorder is the inorder traversal of the same tree, construct and return the binary tree.

Idea: pre: root-left-right
      in: left-root-right

Algo: Take preorder first ele as root and divide remaining based on root from inorder and left and right
      recursively do for left and right by using newly divided traversals.

Code-1: 
class Solution {
public:

    unordered_map<int,int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    int inStart,
                    int inEnd){

        if(inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int pos = mp[root->val];

        root->left = build(preorder, inStart, pos-1);

        root->right = build(preorder, pos+1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;

        return build(preorder,0,inorder.size()-1);
    }
};

  
Code-2: Mine

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()<=0) return NULL;
        if(preorder.size()==1) return new TreeNode(preorder[0]);

        TreeNode* temp=new TreeNode(preorder[0]);
        int i=0;
        while(i<inorder.size() && inorder[i]!=preorder[0]) i++;
        int n=inorder.size();
        vector<int> pre;
        vector<int> inord;
        if(i==0){
            temp->left=NULL;

            inord.assign(inorder.begin()+1,inorder.end());
            pre.assign(preorder.begin()+1,preorder.end());
            temp->right=buildTree(pre,inord);
        }
        else if(i==n-1){
            inord.assign(inorder.begin(),inorder.begin()+i);
            pre.assign(preorder.begin()+1,preorder.end());
            temp->left=buildTree(pre,inord);
            temp->right=NULL;
        }
        else{
            inord.assign(inorder.begin(),inorder.begin()+i);
            int n1=inord.size();
            pre.assign(preorder.begin()+1,preorder.begin()+1+n1);
            temp->left=buildTree(pre,inord);

            inord.assign(inorder.begin()+i+1,inorder.end());
            int n2=inord.size();
            pre.assign(preorder.begin()+1+n1,preorder.end());
            temp->right=buildTree(pre,inord);
        }
        return temp;
    }
};
