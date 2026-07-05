https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], 
where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. 
If a vertex is unreachable from the source, its distance should be marked as 10^8. 

Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

Algo: Use Bellman-Ford because:
        It works with negative edge weights.
        It can detect negative weight cycles.
        Dijkstra cannot handle negative edges correctly.
  
Main Idea: The shortest path in a graph with V vertices can contain at most V-1 edges.

Why?
If a path contains V edges, then at least one vertex repeats (by the pigeonhole principle), forming a cycle.
If the cycle is not negative, removing it cannot make the path longer, so it is unnecessary in a shortest path.
Therefore, relaxing all edges V−1 times is sufficient to propagate the shortest distances.

  
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int INF=100000000;
        
        vector<int> dist(V,INF);
        dist[src]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto &e:edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                if(dist[u]!=INF && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(dist[u]!=INF && dist[u]+w<dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};
