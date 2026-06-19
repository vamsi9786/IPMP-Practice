https://leetcode.com/problems/set-matrix-zeroes/description/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Idea: if(mat[i][j]==0) set a mark in first row at idx i [i][0] and first col at idx j [0][j] to indicate that i row and j col should be zeroes
  
Algo:
  1. check if 1st row and 1st col has any zeroes and set firstcolzero and firstrowzero.
  2. mark row and col in first row and first col.
  3. set the cells as 0 based on first row and first col. 
  4. handle firstrow and firstcol.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fcz=0,frz=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                fcz=1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){
                frz=1;
                break;
            }
        }
        //Mark Zeroes
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        //set zeroes
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        //Handle First row and col
        if(frz){
            for(int i=0;i<n;i++) matrix[0][i]=0;
        }
        if(fcz){
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }
    }
};
