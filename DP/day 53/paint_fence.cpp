https://www.lintcode.com/problem/514/
LintCode 514

There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

Algo/Idea:
  Method 1:
      1. if we need to color same as last then new_same=last_diff*(1); (1==>same color)
      2. if we need to color diff from last then new_diff=last_total*(k-1) (k-1 ==> except prev color we have k-1 choices)
      3. so total=new_same+new_diff

  Method 2:
      1. if we need to color same as last then it is equal to diff of last (i.e diff[i-1]) ===> dp[i-2]*(k-1)
      2. if we need to color diff from last then it is last_total*(k-1) ===> dp[i-1]*(k-1)
      3. so total ==> dp[i]=(k-1)*(dp[i-1]+dp[i-2])

Method 1:
class Solution {
public:
    int numWays(int n, int k) {
        // write your code here
        if(n==0 || k==0) return 0;

        int same=0,diff=k;
        for(int i=2;i<=n;i++){
            int newSame=diff;
            int newDiff=(same+diff)*(k-1);
            same=newSame;
            diff=newDiff;
        }
        return same+diff;

    }
};

Method 2:

class Solution {
public:
    int numWays(int n, int k) {
        // write your code here
        if(n==0 || k==0) return 0;
        if(n==1) return k;

        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=k;
        dp[2]=k*k;
        for(int i=3;i<=n;i++){
            dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};
*/
