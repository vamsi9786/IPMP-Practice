https://leetcode.com/problems/escape-the-spreading-fire/description/

You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
        0 represents grass,
        1 represents fire,
        2 represents a wall that you and fire cannot pass through.
You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). 
Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.

Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse.
If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.

Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.

A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).


Use while (lo <= hi) if:
      You are maintaining an ans variable.
      You move pointers with mid ± 1.
      You are solving an "optimize the answer" problem (maximize/minimize).

Use while (lo < hi) if:
    You are shrinking the search space until a single value remains.
    You return lo (or hi) directly.
    You are implementing lower bound, upper bound, first/last occurrence, or a boundary-search template.

Idea: BS on answer + Multi-src BFS

class Solution {
public:
    int m,n;

    bool helper(int mid,vector<vector<int>>& fire,vector<vector<int>>& grid){
        if(mid>=fire[0][0]) return false;

        queue<tuple<int,int,int>> que;
        que.push({0,0,mid});

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[0][0]=true;
        
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};

        while(!que.empty()){
            auto [x,y,t]=que.front();
            que.pop();

            if(x==m-1 && y==n-1) return true;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
                if(grid[nx][ny]!=0 || vis[nx][ny]) continue;

                if(nx==m-1 && ny==n-1){
                    if(t+1<=fire[nx][ny]){
                        que.push({nx,ny,t+1});
                        vis[nx][ny]=true;
                    }
                }
                else{
                    if(t+1<fire[nx][ny]){
                        que.push({nx,ny,t+1});
                        vis[nx][ny]=true;
                    }
                }
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        queue<pair<int,int>> que;
        vector<vector<int>> fire(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    que.push({i,j});
                    fire[i][j]=0;
                }
            }
        }
        
        while(!que.empty()){
            auto it=que.front();
            que.pop();
            int x=it.first,y=it.second;

            if(x>0 && grid[x-1][y]==0 && fire[x-1][y]==INT_MAX){
                fire[x-1][y]=1+fire[x][y];
                que.push({x-1,y});
            }
            if(y>0 && grid[x][y-1]==0 && fire[x][y-1]==INT_MAX){
                fire[x][y-1]=1+fire[x][y];
                que.push({x,y-1});
            }
            if(x+1<m && grid[x+1][y]==0 && fire[x+1][y]==INT_MAX){
                fire[x+1][y]=1+fire[x][y];
                que.push({x+1,y});
            }
            if(y+1<n && grid[x][y+1]==0 && fire[x][y+1]==INT_MAX){
                fire[x][y+1]=1+fire[x][y];
                que.push({x,y+1});
            }
        }

        int low=0,high=m*n;
        int ans=-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(helper(mid,fire,grid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return (ans==m*n)?1000000000:ans;
    }
};
