class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int mx=INT_MIN,ans=0;
        for(int i=0;i<flips.size();i++){
            mx=max(mx,flips[i]);
            if(mx==i+1) ans++;
        }
        return ans;
    }
};
