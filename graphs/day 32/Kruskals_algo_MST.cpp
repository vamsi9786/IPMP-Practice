https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1

Given a weighted, undirected, and connected graph with V vertices and E edges, the task is to find the sum of the weights of the 
edges in the Minimum Spanning Tree (MST) of the graph using Kruskals Algorithm. The graph is represented as an edge list edges[][], 
where edges[i] = [u, v, w] denotes an undirected edge between u and v with weight w.

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
    static bool cmp(const vector<int>& e1,const vector<int>& e2){
        return e1[2]<e2[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),cmp);
        int MSTcost=0;
        vector<vector<int>> MSTedges;
        DSU ds(V);
        
        for(auto &e:edges){
            if(MSTedges.size()==V-1) break;
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionjoin(u,v);
                MSTcost+=w;
                MSTedges.push_back({u,v,w});
            }
        }
        return MSTcost;
    }
};
