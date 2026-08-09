https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/

There are n items each belonging to zero or one of m groups where group[i] is the group that the 
i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. 
The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:

The items that belong to the same group are next to each other in the sorted list.
There are some relations between these items where beforeItems[i] is a list containing all the items that should come 
before the i-th item in the sorted array (to the left of the i-th item).
  
Return any solution if there is more than one solution and return an empty list if there is no solution.

Algo/Idea: do 2 toposorts based on items and grps
           1. Form ItemGraph based on beforeItems ==> an edge between beforeItem ---> item (for all before_Items[item])
           2. Form GrpGraph based on beforeItems_Group ==> if Group[beforeItem]!=Group[item] ==> then an edge Group[beforeItem] --> Group[item]
           3. Do Toposort for ItemsGraph ==> itemTopo.
           4. Do Toposort for GrpGraph ==> grpTopo.
           5. insert all items to respective grps based on obtained itemTopo sort. ItemsinGrp[group[item]].push_back(item)
           6. Based on GrpTopo sort ==> insert items to final result. ==> res.insert(res.begin(),res.end(),ItemsinGrp[g]) 

class Solution {
public:
    vector<int> topo(vector<vector<int>>& adj,vector<int>& indeg){
        int n=adj.size();
        queue<int> q;

        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);

        vector<int> res;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            res.push_back(u);

            for(int &v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        if(res.size()!=n) return {};
        return res;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++) if(group[i]==-1) group[i]=m++;

        vector<vector<int>> itemAdj(n);
        vector<int> itemIndeg(n,0);

        vector<vector<int>> grpAdj(m);
        vector<int> grpIndeg(m,0);

        for(int i=0;i<n;i++){
            for(int x:beforeItems[i]){
                itemAdj[x].push_back(i);
                itemIndeg[i]++;

                if(group[i]!=group[x]){
                    grpAdj[group[x]].push_back(group[i]);
                    grpIndeg[group[i]]++;
                }
            }
        }

        vector<int> grpTopo=topo(grpAdj,grpIndeg);
        if(grpTopo.empty()) return {};

        vector<int> itemTopo=topo(itemAdj,itemIndeg);
        if(itemTopo.empty()) return {};

        vector<vector<int>> itemsInGrp(m);

        for(int item:itemTopo){
            itemsInGrp[group[item]].push_back(item);
        }

        vector<int> ans;
        for(int g:grpTopo){
            for(int item:itemsInGrp[g]){
                ans.push_back(item);
            }
        }

        return ans;
    }
};
