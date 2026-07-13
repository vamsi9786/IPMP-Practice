https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit.
Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. 
You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:
        The maximum number of jobs that can be completed within their deadlines.
        The total maximum profit earned by completing those jobs.

Idea/Algo: Use Greedy+DSU and with path compression

Path compression:
    int find(int i){
        if(par[i]==i) return i;
        return par[i]=find(par[i]);
    }

Without:
    int find(int i){
        while(par[i]!=i) i=par[i];
        return i;
    }

class DSU{
    public:
        vector<int> par;
        DSU(int n){
            par.resize(n);
            for(int i=0;i<n;i++) par[i]=i;
        }
        
        /*int find(int i){
            while(par[i]!=i) i=par[i];
            return i;
        }*/
        //
        
        //Path compression
        // 0 1 2 3 4
        //ex: 0 1 2 2 2
        //find(4)===> par[4]=2 so goes to findPar(2)
        //without compression goes 4->3->2->1 as it wont update
        // 0 1 2 3 4 as 0 1 2 2 2
        
        //This also finds the root.
        //But while returning,
        //it updates every node's parent directly to the root.
        int find(int i){
            if(par[i]==i) return i;
            return par[i]=find(par[i]);
        }
        
        //stores i if freeSlot
        //else stores prev freeSlot
        void occupy(int i){
            if(i==0) return;
            par[i]=find(i-1);
        }
};

class Solution {
  public:
    static bool cmp(const pair<int,int>& p1,const pair<int,int>& p2){
        return p1.second>p2.second;
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<pair<int,int>> pii;
        int mx=0;
        for(int i=0;i<n;i++){
            pii.push_back({deadline[i],profit[i]});
            mx=max(mx,deadline[i]);
        }
        sort(pii.begin(),pii.end(),cmp);

        DSU ds(mx+1);
        
        int jobs=0;
        int cost=0;
        for(auto &it:pii){
            int d=it.first;
            int p=it.second;
            
            int slot=ds.find(d);
            if(slot>0){
                jobs++;
                cost+=p;
                ds.occupy(slot);
            }
        }
        
        return {jobs,cost};
    }
};
