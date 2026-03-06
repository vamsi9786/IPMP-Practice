class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size(),bc=0;
        int l=0,r=n-1;
        sort(people.begin(),people.end());
        while(l<=r){
            if(people[l]+people[r]<=limit) l++;
            r--;
            bc++;
        }
        return bc;
    }
};
