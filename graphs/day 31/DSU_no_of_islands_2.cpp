https://www.lintcode.com/problem/434/

Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). 
Originally, the 2D matrix is all 0 which means there is only sea in the matrix. 
The list pair has k operator and each operator has two integer A[i].x, A[i].y 
means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. 
Return how many island are there in the matrix after each operator.
You need to return an array of size K.

Idea: Use DSU (Dis-joint Set Union) 

====> In union_fn(u,v) ===> merge smaller tree into larger tree size
      ====> void unionjoin(int i,int j){
                        int u=findPar(i);
                        int v=findPar(j);
                        
                        if(u==v) return;
                        
                        if(size[u]<size[v]) swap(u,v);
                        
                        par[v]=u;
                        size[u]+=size[v];
            }

Algo:  For every operation:
            1. If already land: answer.push_back(count); continue;
            2. Mark as land.
            3. Increase island count.
            4. Check 4 neighbors.
                    If neighbor is land:
                        Different parent? Merge and Decrease count.
            5. Store answer.

                        
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */

    vector<int> par,size;

    void unionjoin(int i,int j){
        int u=findPar(i);
        int v=findPar(j);

        if(u==v) return;

        if(size[u]<size[v]) swap(u,v);

        par[v]=u;
        size[u]+=size[v];
    }

    int findPar(int i){
        while(par[i]!=i){
            i=par[i];
        }
        return i;
    }

    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        int k=operators.size();
        par.resize(n*m);
        size.resize(n*m,1);//used to attach smaller tree under bigger tree
        for(int i=0;i<n*m;i++) par[i]=i;

        vector<vector<bool>> land(n,vector<bool>(m,false));

        vector<int> ans;
        int cnt=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(auto &it:operators){
            int r=it.x;
            int c=it.y;
            
            if(land[r][c]){
                ans.push_back(cnt);
                continue;
            }

            land[r][c]=true;
            cnt++;

            int node=r*m+c;
            for(int j=0;j<4;j++){
                int nr=r+dr[j];
                int nc=c+dc[j];

                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(!land[nr][nc]) continue;

                int adjNode=nr*m+nc;
                if(findPar(node)!=findPar(adjNode)){
                    unionjoin(adjNode,node);
                    cnt--;
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
