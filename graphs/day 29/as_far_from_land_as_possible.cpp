https://leetcode.com/problems/as-far-from-land-as-possible/description/

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Idea: Similar to bridge question.
      Do Multi-source BFS (take all 1s into BFS queue).
      One BFS level ===> incr dist by 1. (dist++)

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));

        queue<pair<int,int>> que;
        int one=0,zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    zero++;
                }
                if(grid[i][j]==1){
                    que.push({i,j});
                    one++;
                }
            }
        }

        if(!one || !zero) return -1;

        int dist=0;
        while(!que.empty()){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                auto [x,y]=que.front();
                que.pop();
                if(x>0 && grid[x-1][y]==0){
                    grid[x-1][y]=1;
                    que.push({x-1,y});
                }
                if(y>0 && grid[x][y-1]==0){
                    grid[x][y-1]=1;
                    que.push({x,y-1});
                }
                if(x+1<n && grid[x+1][y]==0){
                    grid[x+1][y]=1;
                    que.push({x+1,y});
                }
                if(y+1<n && grid[x][y+1]==0){
                    grid[x][y+1]=1;
                    que.push({x,y+1});
                }
            }
            dist++;
        }
        return dist-1;
    }
};
