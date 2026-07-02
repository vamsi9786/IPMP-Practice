https://leetcode.com/problems/binary-search-tree-iterator/description/

Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. 
The pointer should be initialized to a non-existent number smaller than any element in the BST.

boolean hasNext() : Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() : Moves the pointer to the right, then returns the number at the pointer.
  
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.



Method 1: O(H) memory ==> not necessary to store entire traversal 

Idea: Use stack and store all left of a node 
      during pop(): pop the ele and if (node->right!=NULL) pushAllLeft(root->right)
      ==> pushAllLeft(root) ==> pushes all ele to stack from root ==>(to)==> root->left---- ele.
  
Code:

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
class BSTIterator {
public:
    stack<TreeNode*> stk;

    void pushAllLeft(TreeNode* root){ // pushes all ele stack from root to all left ele of root
        while(root){
            stk.push(root);
            root=root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* node=stk.top();
        stk.pop();
        if(node->right) pushAllLeft(node->right);

        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};



Method 2: O(n) memory ==> store inorder traversal and move the iterator ptr

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
class BSTIterator {
public:
    vector<int> ans;
    int it;
    int n;
    BSTIterator(TreeNode* root) {
        inorder(root);
        it=-1;
        n=ans.size();
    }
    
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    int next() {
        if(!hasNext()) return -1;
        return ans[++it];
    }
    
    bool hasNext() {
        int s=ans.size();
        if(it+1 >= s) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
