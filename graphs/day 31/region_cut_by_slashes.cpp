https://leetcode.com/problems/regions-cut-by-slashes/description/

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/' and '\',
or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

Methods:
  Method 1: DSU (Disjoint Union Set) with 4 triangles
            Represent each cell as 4 DSU nodes root+(0,1,2,3)
            Numbering example: (0,0)==> 0,1,2,3 (0,1)===> 4,5,6,7 (1,0)====> 8,9,10,11 ======>>>>>
            Each cell: base idx==> base = 4 * (i*n + j) && top=base+0, right=base+1 , bottom=base+2, left=base+3
     Algo: Step 1: Connect inside the cell based on the character.
                   (i). Blank Space: Nothing divides the square.  connect 0,1 then 1,2 then 2,3.
                  (ii). '/'(slash): seperates top+left and right+bottom. connect 0,3 and 1,2.
                 (iii). '\'(Backslash): seperates top+right and left+bottom. connect 0,1 and 2,3.
           Step 2: Connect neighboring cells. 
                  (i). Right neighbor--(i,j+1)cell: right=4*(i*n+j+1)
                        connect root_right and right_left ===> root+1,right+3
                 (ii). Bottom neighbor--(i+1,j)cell: right=4*((i+1)*n+j)
                        connect root_bottomm and bottom_top ===> root+2,bottom+0    
           Step 3: Count no of parent nodes and incr ans (ans++) and return ans.

class DSU{
public:
    vector<int> par,size;
    
    DSU(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) par[i]=i;
    }

    int findPar(int i){
        while(par[i]!=i){
            i=par[i];
        }
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
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();

        DSU ds(4*n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int root=4*(i*n+j);

                char ch=grid[i][j];

                if(ch==' '){
                    ds.unionjoin(root+0,root+1);
                    ds.unionjoin(root+1,root+2);
                    ds.unionjoin(root+2,root+3);
                }
                else if(ch=='/'){
                    ds.unionjoin(root+0,root+3);
                    ds.unionjoin(root+1,root+2);
                }
                else{
                    ds.unionjoin(root+0,root+1);
                    ds.unionjoin(root+2,root+3);
                }

                //right neighbour
                if(j+1<n){
                    int right=4*(i*n+j+1);
                    ds.unionjoin(root+1,right+3);
                }

                //bottom neighbour
                if(i+1<n){
                    int bottom=4*((i+1)*n+j);
                    ds.unionjoin(root+2,bottom+0);
                }
            }
        }

        int ans=0;
        for(int i=0;i<4*n*n;i++){
            if(ds.findPar(i)==i) ans++;
        }

        return ans;
    }
};
