https://leetcode.com/problems/making-a-large-island/description/

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
  

Idea/Algo: 1. give a id to each unique island and store its area in hash map ==> (idx,size)
           2. now for each perform flip i.e store each adjacent island idx and if it is flipped now all islands become one and sz==> sum of all

class Solution {
public:
    int n;
    unordered_map<int,int> mp;

    int dfs(int i,int j,int id,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=n) return 0;
        if(grid[i][j]!=1) return 0;

        grid[i][j]=id;
        return 1+dfs(i-1,j,id,grid)+dfs(i,j-1,id,grid)+dfs(i+1,j,id,grid)+dfs(i,j+1,id,grid);
    }

    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();

        int id=2;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int sz=dfs(i,j,id,grid);
                    mp[id]=sz;
                    ans=max(ans,sz);
                    id++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;

                    if(i>0 && grid[i-1][j]>1) st.insert(grid[i-1][j]);
                    if(j>0 && grid[i][j-1]>1) st.insert(grid[i][j-1]);
                    if(i+1<n && grid[i+1][j]>1) st.insert(grid[i+1][j]);
                    if(j+1<n && grid[i][j+1]>1) st.insert(grid[i][j+1]);

                    int curr=1;
                    for(int x:st){
                        curr+=mp[x];
                    }
                    ans=max(ans,curr);
                }
            }
        }

        return ans;
    }
};



//TLE === DFS
class Solution {
public:
    int n;
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>=n) return 0;
        if(vis[i][j] || grid[i][j]==0) return 0;

        vis[i][j]=true;
        return 1+dfs(i-1,j,grid,vis)+dfs(i,j-1,grid,vis)+dfs(i+1,j,grid,vis)+dfs(i,j+1,grid,vis);
    }

    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();

        queue<pair<int,int>> que;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) que.push({i,j});
            }
        }

        if(que.empty()) return n*n;

        int ans=0;
        while(!que.empty()){
            auto [i,j]=que.front();
            que.pop();
            grid[i][j]=1;
            vector<vector<bool>> vis(n,vector<bool>(n,false));
            ans=max(ans,dfs(i,j,grid,vis));
            grid[i][j]=0;
        }
        return ans;
    }
};
