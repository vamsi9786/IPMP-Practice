https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Algo: Use PostOrder/helper / DFS and flatten according:
      helper fn : do helper(left) and helper(right) and 
                  link root and root->left as root->right=root->left and link leftTail with r (r=prev root->right).
                :returns tail of curr flattened part i.e if rightTail then rightTail else if leftTail then leftTail else root
                                          
  
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
    TreeNode* helper(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* leftTail=helper(root->left);
        TreeNode* rightTail=helper(root->right);
        if(root->left){
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=NULL;

            leftTail->right=temp;
        }
        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return root;
    }

    void flatten(TreeNode* root) {
        if(root==NULL) return;
        helper(root);
    }
};
