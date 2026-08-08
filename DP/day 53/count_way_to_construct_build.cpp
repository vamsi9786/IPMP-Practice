https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1

There is a road passing through a city with N plots on both sides of the road. 
Plots are arranged in a straight line on either side of the road. 
Determine the total number of ways to construct buildings in these plots, ensuring that no two buildings are adjacent to each other.
Specifically, buildings on opposite sides of the road cannot be adjacent.

Using * to represent a plot and || for the road, the arrangement for N = 3 can be visualized as follows: * * * || * * *.

Note: As the answer can be very large, print it mod 109+7.

class Solution {
  public:
    long long mod=1000000007;
  
    int TotalWays(int N) {
        // Code here
        // 0 ===> No building
        // 1 ===> Building
        long long dp0=1;
        long long dp1=1;
        
        for(int i=1;i<=N;i++){
            long long new0=(dp0+dp1)%mod;
            long long new1=dp0%mod;
            
            dp0=new0;
            dp1=new1;
        }
        
        return (dp0*dp0)%mod;
    }
};


class Solution {
  public:
    long long mod=1000000007;
  
    int TotalWays(int N) {
        // Code here
        // 0 ===> No building
        // 1 ===> Building
        vector<long long> dp(N+2,0);
        dp[1]=2;
        if(N==1) return 2*2;
        
        dp[2]=3;
        if(N==2) return 3*3;
        
        for(int i=3;i<=N;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        
        return (dp[N]*dp[N])%mod;
    }
};



//TLE
class Solution {
  public:
    long long mod=1000000007;
  
    long long helper(int i,int flag,vector<vector<int>>& dp){
        if(i==0) return 1;
        
        if(dp[i][flag]!=-1) return dp[i][flag];
        
        int ans=0;
        ans+=(helper(i-1,0,dp)%mod);
        if(!flag) ans+=(helper(i-1,1,dp)%mod);
        
        return dp[i][flag]=(ans)%mod;
    }
  
    int TotalWays(int N) {
        // Code here
        vector<vector<int>> dp(N+1,vector<int>(2,-1));
        long long ans=helper(N,0,dp)%mod;
        
        return (ans*ans)%mod;
    }
};
