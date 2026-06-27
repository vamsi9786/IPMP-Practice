https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 

The binary tree has the following definition:
              struct Node {
                int val;
                Node *left;
                Node *right;
                Node *next;
              }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Optimal: 
1. Recursive [ O(n) O(H) ]
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;

        if (root->left)
            root->left->next = root->right;

        if (root->right && root->next)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
    }
};

2. Iterative [ O(n) O(1) ]
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node* leftmost = root;

        while (leftmost->left) {
            Node* head = leftmost;

            while (head) {
                head->left->next = head->right;

                if (head->next)
                    head->right->next = head->next->left;

                head = head->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};
