https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, 
so please be creative and come up with different approaches yourself.

Idea: store nodes by delimiting with "  " in string.
      change values accordingly: i.e. 1. to_string(node->val) ===> res+=(to_string(node->val))+" "
                                      2. stoi(val) ===> new Node(stoi(val)) ------(val ==== ss>>val) datastream ss(data)
                                      

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string res;
        if(root==NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node=que.front();
            que.pop();

            if(node==NULL){
                res+="N ";
                continue;
            }

            res+=to_string(node->val)+" ";
            que.push(node->left);
            que.push(node->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;

        stringstream ss(data);

        string val;
        ss>>val;

        TreeNode* root=new TreeNode(stoi(val));

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            TreeNode* node=que.front();
            que.pop();

            ss>>val;
            if(val!="N"){
                node->left=new TreeNode(stoi(val));
                que.push(node->left);
            }

            ss>>val;
            if(val!="N"){
                node->right=new TreeNode(stoi(val));
                que.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
