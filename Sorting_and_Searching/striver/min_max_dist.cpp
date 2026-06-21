Minimise Maximum Distance between Gas Stations

Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. 
You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. 
You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. 
Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations. Find the minimum value of ‘dist’.

Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
Result: 0.5
Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. 
Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. 
It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this

#include <bits/stdc++.h>
using namespace std;

// Class that contains methods for optimizing gas station placement
class GasStationOptimizer {
public:
    // Function to calculate number of gas stations required such that
    // no segment exceeds the max allowed distance `dist`
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            // Number of stations needed between arr[i-1] and arr[i]
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;

            // If perfectly divisible, reduce one to avoid extra placement
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    // Function to minimize the maximum distance between gas stations
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0, high = 0;

        // Determine max initial distance between stations
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        long double diff = 1e-6;

        // Binary search to find minimum possible maximum distance
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) low = mid;
            else high = mid;
        }

        return high;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    GasStationOptimizer optimizer;
    long double ans = optimizer.minimiseMaxDistance(arr, k);

    cout << "The answer is: " << ans << "\n";
    return 0;
}
