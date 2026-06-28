https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

Given a Binary Tree, return the diagonal traversal of the binary tree.
Consider lines of slope -1 passing between nodes. Given a Binary Tree, 
return a single list containing all diagonal elements in a binary tree belonging to same line.

If the diagonal element are present in two different subtrees then left subtree diagonal element should be taken first and then right subtree. 

Idea: For every diagonal:
          Moving right keeps you on the same diagonal.
          Moving left moves you to the next diagonal, so those nodes are saved in the queue and processed later.

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> res;
        if(root==NULL) return res;
        
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()){
            Node* curr=que.front();
            que.pop();
            
            while(curr){
                res.push_back(curr->data);
                if(curr->left) que.push(curr->left);
                curr=curr->right;
            }
        }

        return res;
    }
};
