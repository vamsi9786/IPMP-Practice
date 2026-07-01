https://leetcode.com/problems/closest-binary-search-tree-value/

Return closest value for a value in bst

Method-1: Iterative

class Solution {
public:
    int closestValue(TreeNode* root, double target) {

        int closest = root->val;

        while (root) {
            if(abs(root->val - target) < abs(closest - target)) {
              closest=root->val;
            }

            if(target < root->val) root=root->left;
            else root=root->right;
        }

        return closest;
    }
};

Method-2: recursive

class Solution {
public:
    int closestValue(TreeNode* root, double target){
        if(!root) return INT_MAX;
      
        int closest=root->val;
      
        if(target < root->val && root->left){
            int left = closestValue(root->left, target);
            if (abs(left - target) < abs(closest - target)){
                closest = left;
            }
        }
        else if (target > root->val && root->right) {
            int right = closestValue(root->right, target);
            if (abs(right - target) < abs(closest - target)){
                closest = right;
            }
        }

        return closest;
    }
};
