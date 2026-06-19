https://takeuforward.org/data-structure/count-inversions-in-an-array

Count inversions in an array

Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
        Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Example 1:
Input Format: N = 5, array[] = {1,2,3,4,5}
Result: 0
Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. 
More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.

Example 2:
Input Format: N = 5, array[] = {5,4,3,2,1}
Result: 10
Explanation: we have a reverse sorted array and we will get the maximum inversions as for i < j we will always find a pair such that A[j] < A[i]. 

Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will satisfy out conditions and 
for reverse sorted array we will get maximum inversions and that is (n)*(n-1) / 2.For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

CODE:
  
#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves and count inversions
int merge(vector<int> &arr, int low, int mid, int high) {
    // Temporary array to store merged elements
    vector<int> temp;

    // Starting index of left half
    int left = low;
    // Starting index of right half
    int right = mid + 1;

    // Variable to count inversions
    int cnt = 0;

    // Merge elements in sorted order and count inversions
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // All remaining left elements are inversions
            right++;
        }
    }

    // If left half still has elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If right half still has elements
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    // Return inversion count
    return cnt;
}

// Merge sort function that counts inversions
int mergeSort(vector<int> &arr, int low, int high) {
    // Variable to store inversion count
    int cnt = 0;

    // Base case
    if (low >= high) return cnt;

    int mid = (low + high) / 2;

    // Count inversions in left half
    cnt += mergeSort(arr, low, mid);
    // Count inversions in right half
    cnt += mergeSort(arr, mid + 1, high);
    // Count inversions during merge
    cnt += merge(arr, low, mid, high);

    return cnt;
}

// Function to get number of inversions
int numberOfInversions(vector<int>& a, int n) {
    return mergeSort(a, 0, n - 1);
}

int main() {
    // Input array
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();

    // Count inversions
    int cnt = numberOfInversions(a, n);

    cout << "The number of inversions are: " << cnt << endl;

    return 0;
}
