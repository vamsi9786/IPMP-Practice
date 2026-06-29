https://leetcode.com/problems/binary-tree-cameras/description/

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor 
its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Algo: Idea: dont place at leaf nodes. place at non-leaf so itself, children, grandpar is covered.

      Use DFS and 3 status for DFS == 0 ==> represents not covered
                                      1 ==> represents have camera
                                      2 ==> represents covered but no camera
      Algo: In DFS ==> if any one of children not covered then camera should be installed == return 1
                       if any one of children has camera then no camera req == return 2 
                       else return 0 == not covered
      Note: if null node then return 2 == covered (required to skip leaf nodes)
                       

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
    int cameras=0;
    //dfs status
    //0 Not covered
    //1 Has camera 
    //2 covered but not has camera

    int dfs(TreeNode* root){
        if(root==NULL) return 2;

        int left=dfs(root->left);
        int right=dfs(root->right);

        if(left==0 || right==0){
            cameras++;
            return 1;
        }

        if(left==1 || right==1){
            return 2;
        }

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if(dfs(root)==0) cameras++;
        return cameras;
    }
};
