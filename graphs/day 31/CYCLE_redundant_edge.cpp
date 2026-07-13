https://leetcode.com/problems/redundant-connection/description/

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.


class DSU{
    public:
        vector<int> par,size;

        DSU(int n){
            par.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++) par[i]=i;
        }

        int findPar(int i){
            while(par[i]!=i) i=par[i];
            return i;
        }

        void unionjoin(int i,int j){
            int u=findPar(i);
            int v=findPar(j);

            if(u==v) return;

            if(size[u]<size[v]) swap(u,v);

            par[v]=u;
            size[u]+=size[v];
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU ds(n+1);

        for(auto &e:edges){
            if(ds.findPar(e[0])!=ds.findPar(e[1])){
                ds.unionjoin(e[0],e[1]);
            }
            else return {e[0],e[1]};
        }
        return {};
    }
};
