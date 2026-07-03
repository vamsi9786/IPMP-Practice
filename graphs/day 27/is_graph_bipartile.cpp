https://leetcode.com/problems/is-graph-bipartite/description/

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. 
You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. 
More formally, for each v in graph[u], there is an undirected edge between node u and node v. 

The graph has the following properties:
      1. There are no self-edges (graph[u] does not contain u).
      2. There are no parallel edges (graph[u] does not contain duplicate values).
      3. If v is in graph[u], then u is in graph[v] (the graph is undirected).
      4. The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
      5. A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge 
      6. in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

What is a Bipartite Graph?
        A graph is bipartite if we can divide all vertices into two groups such that:     
                    Every edge goes between the two groups.
                    No edge exists within the same group.

        Instead of thinking about two groups, we think about two colors.

  =====>>> We use bfs/dfs for all nodes for disconnected components
           Why Do We Check Every Node? Graph may be disconnected.

Method-1:
BFS Solution 

Algorithm:
          1. Create a color array initialized to -1 (uncolored).
          2. For every node:
                  If it is uncolored, start a BFS.
                  Assign it color 0.
            For each neighbor:
                  If uncolored, assign the opposite color (1 - color[node]).
                  If already colored with the same color as the current node, return false.
                  If all components are processed without conflict, return true.

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]!=-1) continue;

            queue<int> que;
            que.push(i);
            color[i]=0;

            while(!que.empty()){
                int node=que.front();
                que.pop();

                for(int v:graph[node]){
                    if(color[v]==-1){
                        color[v]=1-color[node];
                        que.push(v);
                    }
                    else if(color[node]==color[v]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

Method-2: DFS Solution

class Solution {
public:
    bool dfs(int node,int c,vector<int>& color,vector<vector<int>>& graph){
        color[node]=c;
        for(int v:graph[node]){
            if(color[v]==-1){
                if(!dfs(v,1-c,color,graph)){
                    return false;
                }
            }
            else if(color[node]==color[v]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};
