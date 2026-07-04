https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], 
where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. 
  
Find the number of strongly connected components in the graph.

Idea: When we reverse the graph the SCC Components wont change 
      ex: 1<->2<->0->3->4
      after reversing 1<->2<->0<-3<-4 
      0,1,2 dfs wont change

Algo: We use 2 DFS: DFS-1===>DFS on normal graph and store vis nodes in stack
                    DFS-2===>DFS on reversed graph based on ele in stack. for each dfs ===> scc++

Code:
class Solution {
  public:
    void dfs1(int node,vector<vector<int>>& adj,vector<bool>& vis,stack<int>& stk){
        vis[node]=true;
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                dfs1(neigh,adj,vis,stk);
            }
        }
        stk.push(node);
    }
    
    void dfs2(int node,vector<vector<int>>& rev,vector<bool>& vis){
        vis[node]=true;
        for(int neigh:rev[node]){
            if(!vis[neigh]){
                dfs2(neigh,rev,vis);
            }
        }
    }
  
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V),rev(V);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            rev[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(V,false);
        stack<int> stk;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs1(i,adj,vis,stk);
            }
        }
        
        fill(vis.begin(),vis.end(),false);
        int scc=0;
        while(!stk.empty()){
            int node=stk.top();
            stk.pop();
            if(!vis[node]){
                dfs2(node,rev,vis);
                scc++;
            }
        }
        return scc;
    }
};
