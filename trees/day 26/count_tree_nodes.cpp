

Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Method-1: O(H2) H=log(n) H=depth/height of BT
Algo: For every subtree:
                Compute the leftmost height.
                Compute the rightmost height.
                If they are equal:  It is a perfect binary tree. Return 2^h - 1.
                Otherwise: Count recursively: 1 + countNodes(left) + countNodes(right).

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
    int leftHt(TreeNode* root){
        int h=0;
        while(root){
            root=root->left;
            h++;
        }
        return h;
    }

    int rightHt(TreeNode* root){
        int h=0;
        while(root){
            root=root->right;
            h++;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lH=leftHt(root);
        int rH=rightHt(root);

        if(lH==rH) return (1 << lH)-1; //(2^h)-1

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

  
Method-2: O(n)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
