https://leetcode.com/problems/merge-intervals/description/

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and 
return an array of the non-overlapping intervals that cover all the intervals in the input.

Algo: similar to min no of platforms.
      sort st of intervals and end of intervals


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<int> start,end;
        int n=intervals.size();
        for(auto &x:intervals){
            int st=x[0];
            int en=x[1];
            start.push_back(st);
            end.push_back(en);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=1,j=0,flag=0;
        int x=start[0],y=end[0];
        while(i<n && j<n){
            if(start[i]<=end[j]){
                y=max(end[i],y);
                i++;j++;
            }
            else{
                res.push_back({x,y});
                x=start[i];
                j++;
                y=end[j];
                i++;
            }
        }
        res.push_back({x,y});
        return res;
    }
};
