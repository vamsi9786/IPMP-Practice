https://leetcode.com/problems/n-queens/description/

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int r=row,c=col;
        //North-West Direction
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        //South-West Direction
        r=row;c=col;
        while(r<n && c>=0){
            if(board[r][c]=='Q') return false;
            r++;
            c--;
        }
        //left direction
        r=row;c=col;
        while(c>=0){
            if(board[r][c]=='Q') return false;
            c--;
        }
        return true;
    }

    void helper(int col,int n,vector<string>& board,vector<vector<string>>& res){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                helper(col+1,n,board,res);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<vector<string>> res;
        helper(0,n,board,res);
        return res;
    }
};
