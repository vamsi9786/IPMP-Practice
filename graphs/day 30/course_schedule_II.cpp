https://leetcode.com/problems/course-schedule-ii/description/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, 
return any of them. If it is impossible to finish all courses, return an empty array.

Idea/Algo: Use topo sort.
           if(ans.size()!=n) ====> This indicates there exists a cycle
            (topo_sort.size()!=V)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &e:prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) que.push(i);
        }

        vector<int> ans;
        while(!que.empty()){
            int u=que.front();
            que.pop();

            ans.push_back(u);
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0) que.push(v);
            }
        }
        if(ans.size()!=n) return {};
        return ans;
    }
};
