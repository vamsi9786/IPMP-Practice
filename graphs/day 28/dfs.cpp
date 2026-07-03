https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], 
where each adj[i] represents the list of vertices connected to vertex i. 
Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, 
and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

class Solution {
  public:
    vector<int> ans;
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis){
        if(vis[node]) return;
        vis[node]=true;
        ans.push_back(node);
        for(int &v:adj[node]){
            dfs(v,adj,vis);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool> vis(n,false);
        dfs(0,adj,vis);
        return ans;
    }
};
