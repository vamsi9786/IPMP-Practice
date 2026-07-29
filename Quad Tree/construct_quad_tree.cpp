https://leetcode.com/problems/construct-quad-tree/description/

Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. 
Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
  
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.


/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isGridLeaf(int st,int end,int n,vector<vector<int>>& grid){
        int orig=grid[st][end];
        for(int i=st;i<st+n;i++){
            for(int j=end;j<end+n;j++){
                if(grid[i][j]!=orig) return false;
            }
        }
        return true;
    }

    Node* helper(int st,int end,int n,vector<vector<int>>& grid){
        Node* root=new Node();

        if(isGridLeaf(st,end,n,grid)){
            if(grid[st][end]==0) root->val=false;
            else root->val=true;
            root->isLeaf=true;
            return root;
        }

        root->val=true;
        root->isLeaf=false;
        root->topLeft=helper(st,end,n/2,grid);
        root->topRight=helper(st,end+(n/2),n/2,grid);
        root->bottomLeft=helper(st+(n/2),end,n/2,grid);
        root->bottomRight=helper(st+(n/2),end+(n/2),n/2,grid);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        
        return helper(0,0,n,grid);
    }
};
