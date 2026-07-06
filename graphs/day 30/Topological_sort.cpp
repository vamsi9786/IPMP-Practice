https://www.geeksforgeeks.org/topological-sorting/

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], 
where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, 
vertex u comes before v in the ordering.
  
Note: As there are multiple Topological orders possible, you may return any of them. 
If your returned Topological sort is correct then the output will be true else false.

Method-1: BFS (Kahns Algo)
Method-2: DFS+Stack
Method-3: DFS+Stack (reverse the vector instead of stack)
  
Method-1: Kahns algo
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

Method-2: DFS+Stack
class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis,stack<int>& stk){
        vis[node]=true;
        
        for(int v:adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis,stk);
            }
        }
        stk.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<bool> vis(V,false);
        stack<int> stk;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,stk);
        }
        
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};

Method-3: DFS+ans (reverse ans===> stack implementation)
class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& ans){
        vis[node]=true;
        
        for(int v:adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis,ans);
            }
        }
        ans.push_back(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<bool> vis(V,false);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,ans);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
