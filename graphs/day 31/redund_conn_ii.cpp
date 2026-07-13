https://leetcode.com/problems/redundant-connection-ii/description/

In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node,
plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), 
with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] 
that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array.

Idea: Use DSU + 2 parents
  There are two possible violations in a directed graph:
        1. A node has two parents. 
        2. There is a cycle.

The correct algorithm :
          There are three cases:
              Case 1: Only cycle ===> No node has indegree 2. Answer = edge creating the cycle. DSU alone works.
              Case 2: Both cycle and two parents ===> Now a node has two parents and a cycle.
                                                      Answer is not always the second parent.
                                                      Need to test both candidates.
              Case 3: Only two parents ==> No cycle. Answer = second incoming edge.

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

        bool unionjoin(int i,int j){
            int u=findPar(i);
            int v=findPar(j);

            if(u==v) return false;

            if(size[u]<size[v]) swap(u,v);

            par[v]=u;
            size[u]+=size[v];
            return true;
        }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        vector<int> parent(n+1,0);

        vector<int> cand1,cand2;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];

            if(parent[v]==0){
                parent[v]=u;
            }
            else{
                cand1={parent[v],v};
                cand2={u,v};

                //ignore this edge later
                e[1]=0;
            }
        }

        DSU ds(n+1);
        for(auto &e:edges){
            if(e[1]==0) continue;

            int u=e[0];
            int v=e[1];
            /*if(!ds.unionjoin(u,v)){
                if(cand1.empty()) return e;

                //cycle+2 parents
                //it is cand1 as we are ignoring 2nd edge [(e[1]==0)continue]
                return cand1; 
            }*/

            if(ds.findPar(u)!=ds.findPar(v)){
                ds.unionjoin(u,v);
            }
            //cycle exists
            else{
                //only cycle exists
                if(cand1.empty()) return e;

                //cycle+2 parents
                //it is cand1 as we are ignoring 2nd edge [(e[1]==0)continue]
                //due to cand1 only cycle coming
                return cand1;
            }
        }
        
        //2 parents
        //2 ans so we give last occur edge
        return cand2;
    }
};
