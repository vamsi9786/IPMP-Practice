https://leetcode.com/problems/01-matrix/description/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two cells sharing a common edge is 1.

Idea:
      First Thought (Wrong) For every cell containing 1, run BFS until you find a 0.

  Instead: Better Observation:Instead of asking
                              For every 1, where is the nearest 0?
                              Ask: Let every 0 simultaneously spread its distance.
           Then BFS spreads outward. The first time a cell is reached, it is guaranteed to be from the nearest zero.

(The waves spread simultaneously. When a cell is touched for the first time, that wave came from the nearest zero.So we never need to update it again.)
  
This is called Multi-Source BFS.

Method 1: O(mxn)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));

        queue<pair<int,int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    que.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!que.empty()){
            auto [x,y]=que.front();
            que.pop();
            if(x>0 && dist[x-1][y]==-1){
                dist[x-1][y]=dist[x][y]+1;
                que.push({x-1,y});
            }
            if(y>0 && dist[x][y-1]==-1){
                dist[x][y-1]=dist[x][y]+1;
                que.push({x,y-1});
            }
            if(x+1<m && dist[x+1][y]==-1){
                dist[x+1][y]=dist[x][y]+1;
                que.push({x+1,y});
            }
            if(y+1<n && dist[x][y+1]==-1){
                dist[x][y+1]=dist[x][y]+1;
                que.push({x,y+1});
            }
        }
        return dist;
    }
};

Method 2: O((m*n)^2)

class Solution {
public:
    int m;
    int n;
    int bfs(int i,int j,vector<vector<int>>& mat){
        if(i<0 || j<0 || i>m-1 || j>n-1) return INT_MAX;
        
        queue<pair<int,int>> que;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        que.push({i,j});

        int d=-1;
        while(!que.empty()){
            int sz=que.size();
            d++;
            for(int k=0;k<sz;k++){
                auto it=que.front();
                int x=it.first,y=it.second;
                que.pop();
                if(vis[x][y]) continue;
                if(mat[x][y]==0) return d;
                if(x>0 && !vis[x-1][y]) que.push({x-1,y});
                if(x+1<m && !vis[x+1][y]) que.push({x+1,y});
                if(y>0 && !vis[x][y-1]) que.push({x,y-1});
                if(y+1<n && !vis[x][y+1]) que.push({x,y+1});
                vis[x][y]=true;
            }
        }
        return INT_MAX;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));

        queue<pair<int,int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    que.push({i,j});
                    //ans[i][j]=bfs(i,j,mat);
                }
            }
        }
        while(!que.empty()){
            auto it=que.front();
            que.pop();
            ans[it.first][it.second]=bfs(it.first,it.second,mat);
        }
        return ans;
    }
};
