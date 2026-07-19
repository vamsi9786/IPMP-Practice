

A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. 
The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.

Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running,
stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.

class Solution {
public:

    int helper(int day, int last,
               vector<vector<int>>& points,
               vector<vector<int>>& dp) {

        if(day == 0){

            int maxi = 0;

            for(int task = 0; task < 3; task++){

                if(task != last)
                    maxi = max(maxi, points[0][task]);
            }

            return maxi;
        }

        if(dp[day][last] != -1)
            return dp[day][last];

        int ans = 0;

        for(int task = 0; task < 3; task++){

            if(task != last){

                ans = max(ans, points[day][task] + helper(day-1, task,points, dp));
            }
        }

        return dp[day][last] = ans;
    }

    int ninjaTraining(int n, vector<vector<int>>& points) {

        vector<vector<int>> dp(n,
                vector<int>(4, -1));

        return helper(n-1, 3, points, dp);
    }
};
