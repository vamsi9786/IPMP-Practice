https://www.geeksforgeeks.org/topological-sorting/

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], 
where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, 
vertex u comes before v in the ordering.
  
Note: As there are multiple Topological orders possible, you may return any of them. 
If your returned Topological sort is correct then the output will be true else false.

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        queue<int> que;
        vector<bool> vis(V,false);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) que.push(i);
        }
        
        while(!que.empty()){
            int u=que.front();
            que.pop();
            if(vis[u]) continue;
            vis[u]=true;
            ans.push_back(u);
            
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) que.push(v);
            }
        }
        return ans;
    }
};
