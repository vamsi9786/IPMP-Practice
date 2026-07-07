https://www.geeksforgeeks.org/problems/articulation-point2616/1

You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.

Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.

DS Used: 1. dt[] ===> discovery time during dfs
         2. low[] ===> lowest discovery time among all adjacent nodes (including itself) during dfs.
         3. par ===> parent of curr node during dfs.

Idea:  for any child node (v) 
        v ===> 1. v==par ===> continue 
               2. !vis[v] ==> dfs(v,u,----) , update low[u]=min(low[u],low[v]) ,check art_pt condn
               3. vis[v] && v!=par ===> else ===> update low[u]=min(low[u],dt[v])

Condn: 1. Non-root with (low[child] >= dt[node].) ===> if(par!=-1 && low[v]>=dt[u]) ==> isArt[u]=true;
       2. Root with more than one child. ===> if(par==-1 && children>1) isArt[u]=true;

Algo/Idea: 1. Build adjacency list.
           2. Run DFS from every unvisited node.
           3. Maintain: dt[], low[], parent
           4. Apply:
                  Root with more than one child.
                  Non-root with low[v/child] >= dt[node].
                  Return all articulation points.

Code:
class Solution {
  public:
    int timer;
    
    void dfs(int u,int par,vector<vector<int>>& adj,vector<int>& dt,vector<int>& low,vector<bool>& isArt,
    vector<bool>& vis){
        vis[u]=true;
        dt[u]=low[u]=timer++;
        int children=0;
        
        for(int v:adj[u]){
            if(v==par) continue;
            
            if(!vis[v]){
                children++;
                dfs(v,u,adj,dt,low,isArt,vis);
                low[u]=min(low[u],low[v]);
                
                if(par!=-1 && low[v]>=dt[u]) isArt[u]=true;
            }
            else{
                low[u]=min(low[u],dt[v]);
            }
        }
        if(par==-1 && children>1) isArt[u]=true;
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> dt(V,-1);
        vector<int> low(V,-1);
        vector<bool> isArt(V,false);
        vector<bool> vis(V,false);
        
        timer=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,adj,dt,low,isArt,vis);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(isArt[i]) ans.push_back(i);
        }
        if(ans.empty()) return {-1};
        return ans;
    }
};
