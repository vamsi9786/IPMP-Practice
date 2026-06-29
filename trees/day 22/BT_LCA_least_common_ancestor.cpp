https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

Given the root of a binary tree with all unique values and two nodes value, n1 and n2.
Find the lowest common ancestor of the given two nodes. Both node values are always present in the Binary Tree.

Note: LCA is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

Idea: Search in both left and right subtree
      For every node, there are 3 possibilities:
          Both nodes are in the left subtree.
          Both nodes are in the right subtree.
          One node is in the left subtree and the other is in the right subtree.
          
          In Case 3, the current node is the Lowest Common Ancestor (LCA).

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
    Node* ans=NULL;
    
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        if(root==NULL) return NULL;
        
        if(root->data==n1 || root->data==n2) return root;
        
        Node* left=lca(root->left,n1,n2);
        Node* right=lca(root->right,n1,n2);
        
        if(left && right) return root;
        if(left) return left;
        return right;
    }
};
