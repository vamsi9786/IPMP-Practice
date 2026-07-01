Problem Statement: Given a Binary Tree and a reference to a root belonging to it. Return the path from the root node to the given leaf node.
Note: No two nodes in the tree have the same data value and it is assured that the given node is present and a path always exists.

Binary Tree: 1 2 3 4 5 -1 -1 -1 -1, Node: 7
Output: [1, 2, 5, 7] 

Idea: Do DFS: add ele at start and if not part of path then backtrack the ele by removing it

Code:
// Structure for a binary tree node
struct TreeNode {
    // Value of the node
    int val;

    // Pointers to left and right children
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class containing the solution
class Solution {
public:
    // Function to find the path from root to node with value x
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        // If current node is NULL, return false
        if (!root) {
            return false;
        }

        // Add current node's value to the path
        arr.push_back(root->val);

        // If current node's value is equal to x, return true
        if (root->val == x) {
            return true;
        }

        // Recursively search in left or right subtree
        if (getPath(root->left, arr, x) ||
            getPath(root->right, arr, x)) {
            return true;
        }

        // If not found, backtrack and remove current node
        arr.pop_back();
        return false;
    }

    // Function to get the path from root to node with value B
    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
      
        if (A == NULL) {
            return arr;
        }
      
        getPath(A, arr, B);

        return arr;
    }
};

