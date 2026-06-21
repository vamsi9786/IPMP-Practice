roblem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a 
number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.

#include <bits/stdc++.h>
using namespace std;
        
class Solution {
public:
    // Function to find N-th root of M using binary search
    int nthRoot(int n, int m) {
        // Set low and high for binary search
        int low = 1, high = m;

        // Start binary search
        while (low <= high) {
            // Calculate mid
            int mid = (low + high) / 2;

            // Store result of mid^n
            long long ans = 1;
            for (int i = 0; i < n; i++) {
                ans *= mid;
                if (ans > m) break;
            }

            // If mid^n equals m
            if (ans == m) return mid;

            // If mid^n is less than m
            if (ans < m) low = mid + 1;

            // If mid^n is more than m
            else high = mid - 1;
        }

        // Return -1 if not found
        return -1;
    }
};

// Main function
int main() {
    Solution obj;
    int result = obj.nthRoot(3, 27);
    return 0;
}
