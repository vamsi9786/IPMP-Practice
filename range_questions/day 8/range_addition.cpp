O(n+m) Prefix Sum

Algo:
    1. add the increment at start idx and at idx==>(end_idx + 1) subtract the increment 
            let inc =2; st=1 end=4
                    0 2 0 0 0 -2
                    0 2 2 2 2 0  prefix sum logic

class Solution {
public:
    //Prefix Sum
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> ans(length,0);
        for(auto &u:updates){
            int st=u[0],en=u[1],inc=u[2];
            ans[st]+=inc;
            if(en+1<length){
                ans[en+1]-=inc;
            }
        }
        for(int i=1;i<length;i++){
            ans[i]+=ans[i-1];
        }
        return ans;
    }
};
