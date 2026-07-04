https://www.geeksforgeeks.org/problems/mother-vertex/1

Given a directed graph with V vertices labeled from 0 to V-1 and a list of edges edges[][], 
where each edge is represented as [u, v] indicating a directed edge from vertex u to vertex v, find a Mother Vertex of the graph.

A Mother Vertex is a vertex from which all other vertices can be reached.
          If multiple such vertices exist, return the one with the smallest value.
          If no such vertex exists, return -1.


Idea: Do DFS for all vertices and mark vis.
      Do DFS from node 0 to V-1 as we need smallest mother node.

class Solution {
  public:
    void dfs(int node,vector<bool>& vis,vector<vector<int>>& adj){
        vis[node]=true;
        
        for(int nei:adj[node]){
            if(!vis[nei]){
                dfs(nei,vis,adj);
            }
        }
    }
    
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<bool> vis(V,false);
        
        // as we need smallest so we go from 0 to V-1
        int ans=-1;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans=i;
            }
        }
        
        //verify the ans
        vector<bool> vis2(V,false);
        dfs(ans,vis2,adj);
        for(int i=0;i<V;i++){
            if(!vis2[i]) return -1;
        }
        
        return ans;
    }
};
