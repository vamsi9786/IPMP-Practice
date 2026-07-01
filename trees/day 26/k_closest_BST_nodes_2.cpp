https://leetcode.com/problems/closest-binary-search-tree-value-ii/

Return k closest nodes in BST for a int value.

Idea: The optimal interview solution uses two stacks:
                Predecessor stack (values ≤ target)
                Successor stack (values > target)

      Each stack acts like an iterator. 
      Time: O(H + K) Space: O(H), where H is the height of the BST.

Code:
class Solution {
public:

    void initPred(TreeNode* root, double target, stack<TreeNode*>& pred){
        while(root){
            if(root->val <= target){
                pred.push(root);
                root = root->right;
            } 
            else{
                root = root->left;
            }
        }
    }

    void initSucc(TreeNode* root, double target, stack<TreeNode*>& succ) {
        while(root){
            if(root->val > target){
                succ.push(root);
                root = root->left;
            } 
            else{
                root = root->right;
            }
        }
    }

    int getPred(stack<TreeNode*>& pred) {
        TreeNode* node = pred.top();
        pred.pop();

        int val = node->val;

        node = node->left;
        while (node) {
            pred.push(node);
            node = node->right;
        }

        return val;
    }

    int getSucc(stack<TreeNode*>& succ) {
        TreeNode* node = succ.top();
        succ.pop();

        int val = node->val;

        node = node->right;
        while (node) {
            succ.push(node);
            node = node->left;
        }

        return val;
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {

        stack<TreeNode*> pred, succ;

        initPred(root, target, pred);
        initSucc(root, target, succ);

        vector<int> ans;

        while (k--) {

            if (pred.empty()) {
                ans.push_back(getSucc(succ));
            }
            else if (succ.empty()) {
                ans.push_back(getPred(pred));
            }
            else {

                if (abs(pred.top()->val - target) <=
                    abs(succ.top()->val - target))
                    ans.push_back(getPred(pred));
                else
                    ans.push_back(getSucc(succ));
            }
        }

        return ans;
    }
};
