https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1

Given an array arr[] representing preorder traversal of a BST. You have to build the BST  from the given preorder.

Method-1: O(n)

Algo: use preorder ( root-left-right) so move preorder from 0 to n-1;
      if(idx>n-1) or if( pre[idx] is out of bounds ) then return NULL
      else create root node and do root->left and root->right as preorder

/* class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    int idx;
    
    Node* build(vector<int>& pre,int low,int high){
        if(idx>=pre.size()) return NULL;
        
        if(pre[idx]<low || pre[idx]>high) return NULL;
        
        Node* root=new Node(pre[idx]);
        idx++;
        
        root->left=build(pre,low,root->data);
        root->right=build(pre,root->data,high);
        return root;
    }
    
    Node* preToBST(vector<int>& pre) {
        // code here
        idx=0;
        return build(pre,INT_MIN,INT_MAX);
    }
};
