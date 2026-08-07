https://www.geeksforgeeks.org/dsa/weighted-job-scheduling-set-2-using-lis/

Given a 2D array jobs of size n × 3, where each row jobs[i] contains three integers:

jobs[i][0] – the start time of the ith job
jobs[i][1] – the end time of the ith job
jobs[i][2] – the profit earned if this job is selected
The task is to select a subset of non-overlapping jobs such that the total profit is maximized. 
A job ending at time t can be followed by another job that starts at time t (no overlap if end time of one is equal to start time of the next).


Code:

// C++ program to find maximum profit subset 
// of non-overlapping jobs using LIS-style DP
#include <bits/stdc++.h>
using namespace std;

// Function to return the job list contributing to max profit
vector<vector<int>> maxProfit(vector<vector<int>> &jobs) {
    int n = jobs.size();

    // Sort jobs based on start time
    sort(jobs.begin(), jobs.end());

    // dp[i] stores max profit starting from job i
    vector<int> dp(n);
    
    // To reconstruct the job list
    vector<int> nextIndex(n, -1);

    int maxProfit = 0;
    int startIndex = -1;

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = jobs[i][2];
        int next = -1;

        // Find next non-overlapping job
        for (int j = i + 1; j < n; j++) {
            if (jobs[i][1] <= jobs[j][0]) {
                if (dp[i] < jobs[i][2] + dp[j]) {
                    dp[i] = jobs[i][2] + dp[j];
                    next = j;
                }
            }
        }

        nextIndex[i] = next;

        if (dp[i] > maxProfit) {
            maxProfit = dp[i];
            startIndex = i;
        }
    }

    // Reconstruct job sequence
    vector<vector<int>> res;
    while (startIndex != -1) {
        res.push_back({jobs[startIndex][0],
                          jobs[startIndex][1], 
                          jobs[startIndex][2]});
                          
        startIndex = nextIndex[startIndex];
    }

    return res;
}

int main() {
    vector<vector<int>> jobs = {
        {1, 2, 50},
        {3, 5, 20},
        {6, 19, 100},
        {2, 100, 200}
    };

    vector<vector<int>> result = maxProfit(jobs);

    for (auto &job : result) {
        cout << "[" << job[0] << ", " << job[1] << ", " <<job[2] << "] ";
    }

    return 0;
}
