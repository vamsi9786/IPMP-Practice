https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, 
represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and 
return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer.

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        int m=edges.size();
        
        for(auto &edg:edges){
            int u=edg[0];
            int v=edg[1];
            int w=edg[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        //pq is {wt,u}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        pq.push({0,src});
        dist[src]=0;
        
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            
            if(d>dist[u]) continue;
            
            for(auto[v,w]:adj[u]){
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};
