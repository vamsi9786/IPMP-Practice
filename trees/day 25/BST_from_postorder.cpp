https://www.geeksforgeeks.org/problems/construct-bst-from-post-order/1

Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. 
The output will be inorder traversal of the constructed BST.

Method-1: O(n)
/* Structure of tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    int idx;
    Node* build(vector<int>& post,int low,int high){
        if(idx<0) return NULL;
        
        if(post[idx]<low || post[idx]>high) return NULL;
        
        Node* root=new Node(post[idx--]);
        //idx--;
        
        root->right=build(post,root->data,high);
        root->left=build(post,low,root->data);
        
        return root;
    }
    
    Node* constructTree(vector<int>& post) {
        // code here
        int n=post.size();
        idx=n-1;
        
        return build(post,INT_MIN,INT_MAX);
    }
};

Method-2: O(n2)
/* Structure of tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    Node* insert(Node* root,int x){
        if(root==NULL) return new Node(x);;
        if(root->data<x){
            root->right=insert(root->right,x);
        }
        else{
            root->left=insert(root->left,x);
        }
        return root;
    }
    
    Node* constructTree(vector<int>& post) {
        // code here
        int n=post.size();
        Node* root=new Node(post[n-1]);
        for(int i=n-2;i>=0;i--){
            root=insert(root,post[i]);
        }
        return root;
    }
};
