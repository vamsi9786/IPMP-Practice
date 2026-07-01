https://www.geeksforgeeks.org/problems/construct-tree-from-preorder-postorder/1

Given two arrays pre[] and post[] that represent the preorder and postorder traversals of a full binary tree. 
Your task is to construct the binary tree and return its root.

Note:  Full Binary Tree is a binary tree where every node has either 0 or 2 children. The preorder and postorder traversals contain unique values, 
       and every value present in the preorder traversal is also found in the postorder traversal.

Algo: store map of values(nodes) and idx and split according.

Method: O(n) with hash map
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    unordered_map<int,int> post_mp;

    Node* build(vector<int>& pre,vector<int>& post,int preL,int preR,int postL,int postR){
        if(preL>preR || postL>postR) return NULL;
        if(preL==preR || postL==postR) return new Node(pre[preL]);
        
        Node* root=new Node(pre[preL]);
        
        int idx=post_mp[pre[preL+1]];
        int n1=idx-postL+1;
        
        root->left=build(pre,post,preL+1,preL+n1,postL,idx);
        root->right=build(pre,post,preL+n1+1,preR,idx+1,postR-1);
        
        return root;
    }
  
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int n=pre.size();
        for(int i=0;i<n;i++){
            post_mp[post[i]]=i;
        }
        return build(pre,post,0,n-1,0,n-1);
    }
};
