class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0,cl=-1;
        vector<int> clo(seats.size());
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                clo[i]=-1;
                cl=i;
            }
            else if(seats[i]==0){
                clo[i]=cl;
            }
        }
        cl=-1;
        vector<int> clor(seats.size());
        for(int i=seats.size()-1;i>=0;i--){
            if(seats[i]==1){
                clor[i]=-1;
                cl=i;
            }
            else if(seats[i]==0){
                clor[i]=cl;
            }
        }

        for(int i=0;i<seats.size();i++){
            if(seats[i]==0){
                if(clor[i]!=-1 && clo[i]!=-1){
                    ans=max(ans,min(i-clo[i],clor[i]-i));
                }
                else if(clor[i]==-1 && clo[i]!=-1){
                    ans=max(ans,abs(clo[i]-i));
                }
                else if(clo[i]==-1 && clor[i]!=-1){
                    ans=max(ans,abs(clor[i]-i));
                }
            }
        }
        return ans;
    }
};
