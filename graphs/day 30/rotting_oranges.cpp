https://leetcode.com/problems/rotting-oranges/description/

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Code:
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int fresh=0;
        queue<pair<int,int>> que;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;

        int ans=0;
        while(!que.empty() && fresh){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                auto[x,y]=que.front();
                que.pop();
                if(vis[x][y]) continue;
                vis[x][y]=true;
                if(x>0 && !vis[x-1][y] && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    fresh--;
                    que.push({x-1,y});
                }
                if(y>0 && !vis[x][y-1] && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    fresh--;
                    que.push({x,y-1});
                }
                if(x+1<m && !vis[x+1][y] && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    fresh--;
                    que.push({x+1,y});
                }
                if(y+1<n && !vis[x][y+1] && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    fresh--;
                    que.push({x,y+1});
                }
            }
            ans++;
        }

        return (fresh==0)?ans:-1;
    }
};
