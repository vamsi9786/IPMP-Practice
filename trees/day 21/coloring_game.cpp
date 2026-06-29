https://leetcode.com/problems/binary-tree-coloring-game/description/

Two players play a turn based game on a binary tree. We are given the root of this binary tree, and the number of nodes n in the tree. 
n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x. 
The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player. In each turn, that player chooses a node of their color 
(red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn. 
If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player. If it is possible to choose such a y to ensure you win the game, return true. If it is not possible, return false.

Idea: x divides tree into (left, right and par). for y to win y should choose max_nodes(left,right,par) 
      if max > (n/2) then true else false

Algo: use dfs and count left right. then par=n-left-right-1 

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
    int leftCount=0;
    int rightCount=0;
    int dfs(TreeNode* root,int x){
        if(!root) return 0;
        int lCount=dfs(root->left,x);
        int rCount=dfs(root->right,x);
        if(root->val==x){
            leftCount=lCount;
            rightCount=rCount;
        }
        return lCount+rCount+1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root,x);
        int par=n-leftCount-rightCount-1;
        int ans=max(par,max(leftCount,rightCount));
        return ans>(n/2);
    }
};
