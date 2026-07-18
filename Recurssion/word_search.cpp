https://leetcode.com/problems/word-search/description/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

class Solution {
public:
    int m,n;
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int idx,vector<vector<bool>>& vis){
        if(idx==word.size()) return true;

        if(i<0 || j<0 || i>=m || j>=n|| vis[i][j] || board[i][j]!=word[idx]) return false;

        vis[i][j]=true;

        bool found=dfs(board,word,i-1,j,idx+1,vis) || dfs(board,word,i,j-1,idx+1,vis)
        || dfs(board,word,i+1,j,idx+1,vis) || dfs(board,word,i,j+1,idx+1,vis);

        vis[i][j]=false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && dfs(board,word,i,j,0,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
