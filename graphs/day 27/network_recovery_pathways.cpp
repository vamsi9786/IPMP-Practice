https://leetcode.com/problems/network-recovery-pathways/description/?envType=daily-question&envId=2026-07-03

You are given a directed acyclic graph of n nodes numbered from 0 to n − 1. This is represented by a 2D array edges of length m, 
where edges[i] = [ui, vi, costi] indicates a one‑way communication from node ui to node vi with a recovery cost of costi.

Some nodes may be offline. You are given a boolean array online where online[i] = true means node i is online. Nodes 0 and n − 1 are always online.

A path from 0 to n − 1 is valid if:
            All intermediate nodes on the path are online.
            The total recovery cost of all edges on the path does not exceed k.
            For each valid path, define its score as the minimum edge‑cost along that path.

Return the maximum path score (i.e., the largest minimum-edge cost) among all valid paths. If no valid path exists, return -1.


Method 1:
    Algo: as we need to 'maximize the minimum' so we use binary search on ans.
          we take low as 0 and high as max of all edge wt
          while(low<=high):
             for each mid: we check will the mid satisfy ans.
                          if(check()) then max the ans ==> ans=mid and low=mid+1
                          else high=mid-1
  
    check(): ( we pass (mid ==> min wt edge so we check does there exist a path whose sum<=k using Topological sort/dijkstra ) )
    As the graph is DAG: we prefer Topological sort O(V+E) , dijsktras O((V+E).logV)
                      

class Solution {
public:
    int n;
    //Topological sort as graph is DAG
    bool check(int mid,vector<vector<pair<int,int>>>& adj,vector<bool>& online,long long k){
        vector<int> indegree(n,0);
        for(int u=0;u<n;u++){
            if(u!=0 && u!=n-1 && !online[u]) continue;
            for(auto &[v,w]:adj[u]){
                if(w<mid) continue;
                if(v!=n-1 && !online[v]) continue;
                indegree[v]++;
            }
        }
        
        queue<int> que;
        for(int u=0;u<n;u++){
            if(indegree[u]==0 && online[u]) que.push(u);
        }
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;

        while(!que.empty()){
            int u=que.front();
            que.pop();
            
            if(dist[u]!=LLONG_MAX){
                for(auto &[v,w]:adj[u]){
                    if(w<mid) continue;
                    if(v!=n-1 && !online[v]) continue;
                    dist[v]=min(dist[v],(long long)w+dist[u]);
                }
            }

            for(auto &[v,w]:adj[u]){
                if(w<mid) continue;
                if(v!=n-1 && !online[v]) continue;
                indegree[v]--;
                if(indegree[v]==0) que.push(v);
            }
        }
        return dist[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n=online.size();
        vector<vector<pair<int,int>>> adj(n);

        int low=0,mx=0;
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            mx=max(mx,e[2]);
        }

        int high=mx;
        //Binary search on ans
        //check tells whether there exists a path such that (all edge wt >= mid)
        //also check ensures total sum<=k
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            //int mid=low+(high-low)/2;
            if(check(mid,adj,online,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};


Method-2: Use DFS but this causes TLE.

class Solution {
public:
    long long ans=LLONG_MIN;
    bool flag;
    int n;
    void dfs(int node,int sum,int mn,vector<bool>& vis,vector<vector<pair<int,int>>>& adj,vector<bool>& online,long long k){
        if(sum>k || !online[node] || vis[node]) return;
        if(node==n-1){
            flag=true;
            ans=max(ans,(long long)mn);
            return;
        }
        vis[node]=true;
        for(auto &x:adj[node]){
            int v=x.first;
            int w=x.second;
            dfs(v,sum+w,min(mn,w),vis,adj,online,k);
        }
        vis[node]=false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n=online.size();
        if(n==0 || edges.size()==0) return -1;
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> vis(n,false);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        flag=false;
        dfs(0,0,INT_MAX,vis,adj,online,k);
        return (flag)?ans:-1;
    }
};
