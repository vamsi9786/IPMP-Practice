https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1

An Eulerian Path is a path in graph that visits every edge exactly once. 
An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. 
  
Given an undirected graph with V nodes, and E edges, with adjacency list adj , where adj[i] stores all the nodes that have an edge with i, 
return 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, return 1, otherwise, return 0.

Algo: 1. Count degree of every vertex.
      2. Find one vertex whose degree > 0. and Run DFS.
      3. If any vertex (degree>0) ==> is still unvisited, graph is disconnected. ==> return 0.
      4. Count odd degree vertices.
      5. Return: odd==0  -> 2
                 odd==2  -> 1
                 else    -> 0

class Solution {
  public:
    void dfs(int u,vector<vector<int>>& adj,vector<bool>& vis){
        vis[u]=true;
        for(int v:adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool> vis(V,false);
        
        int st=-1;
        for(int i=0;i<V;i++){
            if(!adj[i].empty()){
                st=i;
                break;
            }
        }
        
        if(st==-1) return 2;
        
        dfs(st,adj,vis);
        
        for(int i=0;i<V;i++){
            if(!vis[i] && !adj[i].empty()){
                return 0;
            }
        }
        
        int odd=0;
        for(int i=0;i<V;i++){
            if(adj[i].size()%2==1) odd++;
        }
        
        if(odd==0) return 2;
        if(odd==2) return 1;
        return 0;
    }
};
