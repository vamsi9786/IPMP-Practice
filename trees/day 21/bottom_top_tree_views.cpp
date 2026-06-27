1. Bottom View

Algo: use level order traversal and hd (horizontal distance) and 
      map for mapping hd and node and update latest val for that hd . last occurred value for that hd is added to result

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
  
    vector<int> bottomView(Node *root) {
        // code here
        if(root==NULL) return {};
        vector<int> res;
        
        queue<pair<Node*,int>> que;
        map<int,int> mp;
        
        que.push({root,0});
        
        while(!que.empty()){
            auto pii=que.front();
            que.pop();
            
            Node* node=pii.first;
            int hd=pii.second;
            int val=node->data;
            mp[hd]=val;
            
            if(node->left) que.push({node->left,hd-1});
            if(node->right) que.push({node->right,hd+1});
        }
        
        for(auto x:mp){
            res.push_back(x.second);
        }
        return res;
    }
};

2.Top View

Algo: use level order traversal and hd (horizontal distance) and 
      map for mapping hd and node and update first val for that hd . first occurence of that hd is added to result

