https://www.geeksforgeeks.org/problems/construct-tree-from-inorder-and-levelorder/1

Given inorder and level-order traversals of a Binary Tree, construct the Binary Tree and return the root Node.

Algo:
      Step 1: If the level-order array is empty, return NULL.
      Step 2: The first element of the level-order traversal is the root. ( Root = levelOrder[0] )
      Step 3: Find the root's index in the inorder traversal.
              This divides the inorder array into: Left subtree and Right subtree
      Step 4: Store all elements of the left inorder in a hash set (or use a map for membership checking).
      Step 5: Traverse the remaining level-order array (excluding the root).
              For each element:
                          If it belongs to the left inorder set → put it in Left Level Order.
                          Otherwise → put it in Right Level Order.
      Step 6: Recursively construct the left subtree using: Left Inorder and Left Level Order.
              root->left=buildtree();
      Step 7: Recursively construct the right subtree using: Right Inorder and Right Level Order.
              root->right=buildTree();
      Step 8: return root;
      

/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

typedef struct Node Node;

Node* build(vector<int> inorder,vector<int> level){
    if(inorder.empty() || level.empty()) return NULL;
    
    Node* root=new Node(level[0]);
    //root->key=level[0];
    root->left=NULL;
    root->right=NULL;
    
    if(inorder.size()==1) return root;
    
    int idx=0;
    while(inorder[idx]!=root->key) idx++;
    
    multiset<int> leftSet,rightSet;
    for(int i=0;i<idx;i++) leftSet.insert(inorder[i]);
    for(int i=idx+1;i<inorder.size();i++) rightSet.insert(inorder[i]);
    
    vector<int> leftIn(inorder.begin(),inorder.begin()+idx);
    vector<int> rightIn(inorder.begin()+idx+1,inorder.end());
    
    vector<int> leftLevel,rightLevel;
    for(int i=1;i<level.size();i++){
        if(leftSet.count(level[i])) leftLevel.push_back(level[i]);
        else rightLevel.push_back(level[i]);
    }
    
    root->left=build(leftIn,leftLevel);
    root->right=build(rightIn,rightLevel);
    return root;
}


Node* buildTree(int inorder[], int levelOrder[], int n) {
    // add code here.
    vector<int> Inorder(inorder,inorder+n);
    vector<int> Levelorder(levelOrder,levelOrder+n);
    Node* root= build(Inorder,Levelorder);
    
    //return preorder(root);
    return root;
}
