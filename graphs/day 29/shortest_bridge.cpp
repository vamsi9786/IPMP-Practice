https://leetcode.com/problems/shortest-bridge/description/

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1s not connected to any other 1s. There are exactly two islands in grid.
You may change 0's to 1 to connect the two islands to form one island.

Return the smallest number of 0 you must flip to connect the two islands.

Idea/Algo: Use Mutli-source BFS:
           Step 1: Find first island.
           Step 2: Run DFS: Mark all its cells visited. and Push every cell into queue.
           Step 3: Run BFS: Each BFS layer means ==> Flip one more water cell.
                            When a neighbor is 1: Second island reached. Return current level.
                
Intuition: There are exactly 2 islands.
          1. We need the minimum number of water cells (0) to flip so that the islands become connected.
          2. Instead of trying every possible flip, we:
                      Find one island using DFS.
                      Put all cells of that island into a queue.
                      Perform BFS simultaneously from all those cells until we reach the second island.
          3. The BFS distance is exactly the number of water cells that need to be flipped.


Code:
class Solution {
public:
    int n;
    void dfs(int i,int j,vector<vector<int>>& grid,queue<pair<int,int>>& que){
        if(i<0 || i>=n || j<0 || j>=n) return;

        if(grid[i][j]!=1) return;
        grid[i][j]=2;
        que.push({i,j});
        dfs(i-1,j,grid,que);
        dfs(i,j-1,grid,que);
        dfs(i+1,j,grid,que);
        dfs(i,j+1,grid,que);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        queue<pair<int,int>> que;
        
        bool found=false;
        for(int i=0;i<n && !found;i++){
            for(int j=0;j<n && !found;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,que);
                    found=true;
                }
            }
        }

        int dist=0;
        while(!que.empty()){
            int sz=que.size();

            for(int i=0;i<sz;i++){
                auto [x,y]=que.front();
                que.pop();

                if(x>0){
                    if(grid[x-1][y]==1) return dist;
                    if(grid[x-1][y]==0){
                        grid[x-1][y]=2;
                        que.push({x-1,y});
                    }
                }
                if(y>0){
                    if(grid[x][y-1]==1) return dist;
                    if(grid[x][y-1]==0){
                        grid[x][y-1]=2;
                        que.push({x,y-1});
                    }
                }
                if(x+1<n){
                    if(grid[x+1][y]==1) return dist;
                    if(grid[x+1][y]==0){
                        grid[x+1][y]=2;
                        que.push({x+1,y});
                    }
                }
                if(y+1<n){
                    if(grid[x][y+1]==1) return dist;
                    if(grid[x][y+1]==0){
                        grid[x][y+1]=2;
                        que.push({x,y+1});
                    }
                }
            }

            dist++;
        }
        return -1;
    }
};
