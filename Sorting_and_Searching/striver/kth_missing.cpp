https://leetcode.com/problems/kth-missing-positive-number/description/

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

 #include <bits/stdc++.h>
using namespace std;

// Class to find the k-th missing number using binary search
class MissingKFinder {
public:
    // Function to return the k-th missing number
    int missingK(vector<int> vec, int n, int k) {
        int low = 0, high = n - 1;

        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2;

            // Calculate how many numbers are missing till vec[mid]
            int missing = vec[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;  // Move right to find more missing numbers
            } else {
                high = mid - 1; // Move left to find a smaller valid index
            }
        }

        // After loop, 'high' points to the largest index such that
        // number of missing elements till there < k
        return k + high + 1;
    }
};

int main() {
    vector<int> vec = {4, 7, 9, 10};  // Sorted array
    int n = vec.size();              // Size of array
    int k = 4;                       // k-th missing number to find

    MissingKFinder finder;          // Create object
    int ans = finder.missingK(vec, n, k);  // Call method

    cout << "The missing number is: " << ans << "\n";  // Print result
    return 0;
}
 
