https://leetcode.com/problems/sum-of-distances-in-tree/description/

There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

Algo:
  DS Used: count[i] = Stores the number of nodes in the subtree rooted at i.
           ans[i] =  During DFS1: stores the sum of distances from node i to nodes in its subtree.
                     After DFS2: stores the sum of distances from node i to all nodes.
  
  Idea: Use 2 dfs
      1. dfs1 = used for computing ans and count (count=no of nodes in that subtree) (ans=sum of distances)
                ( Size of every subtree (count[]).  Sum of distances for the chosen root (ans[0]). )
  
      2. dfs2 = Find answers for every other node using the root answer.
                Instead of recomputing with DFS from every node (O(N²)), derive answers in O(N).
        ===> compute ans[child] = ans[parent] - count[child] + (n-count[child]);
            i.e decrease all nodes in child subtree by 1 and increase all nodes outside by 1.
            

  
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> count;
    vector<int> ans;

    void dfs1(int node,int parent){
        count[node]=1;

        for(int child:graph[node]){
            if(child==parent) continue;
            dfs1(child,node);
            count[node]+=count[child];
            ans[node]+=ans[child]+count[child];
        }
    }

    void dfs2(int node,int parent,int n){
        for(int child:graph[node]){
            if(child==parent) continue;
            ans[child]=(ans[node]-count[child])+(n-count[child]);
            dfs2(child,node,n); 
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        count.resize(n);
        ans.resize(n);

        for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        //use dfs and count 
        dfs1(0,-1);
        dfs2(0,-1,n);
        return ans;
    }
};
