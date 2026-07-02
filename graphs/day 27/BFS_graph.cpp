https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], 
where each adj[i] represents the list of vertices connected to vertex i. 

Perform a Breadth First Search (BFS) traversal starting from vertex 0, 
visiting vertices from left to right according to the given adjacency list, and 
return a list containing the BFS traversal of the graph.

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> ans;
        int n=adj.size();
        
        queue<int> que;
        vector<bool> vis(n,false);
        
        que.push(0);
        vis[0]=true;
        
        while(!que.empty()){
            int val=que.front();
            que.pop();
            
            ans.push_back(val);
            
            for(int &x:adj[val]){
                if(!vis[x]){
                    que.push(x);
                    vis[x]=true;
                }
            }
        }
        return ans;
    }
};
