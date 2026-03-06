https://leetcode.com/problems/k-th-smallest-prime-fraction/1

You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

Optimal using Binary search

Algorithm
      Step 1: Search space i.e low=0 high=1 as all fractions lie in [0,1]
      Step 2: mid=(low+high)/2.0 
                If: count < k → mid is too small (low=mid)
                    count ≥ k → mid is big enough (high=mid)
      Step 3: How do we count fractions ≤ mid efficiently?
              we want: arr[i] / arr[j] ≤ mid, so we rearrange: arr[i] ≤ mid * arr[j]
                    Fix the denominator pointer j from left to right.                  
                    Maintain a numerator pointer i that only moves forward.                
                    For each j, move i while arr[i] ≤ mid × arr[j].                    
                    All indices < i form valid fractions with denominator arr[j].                   
                    Since i never moves backward, total counting runs in O(n) time.
      Step 4: Track the best fraction ≤ mid     
                  While counting, we also track:                 
                  the largest fraction that is still ≤ mid                  
                  Why? : When count ≥ k, the k-th fraction lies at or before mid                  
                  The largest fraction ≤ mid is a candidate answer
      Step 5: Binary search update if(count < k) low=mid; else high=mid;
      Step 6: When do we stop?    (high - low < very small number (like 1e-9) )

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0.0, high = 1.0;

        int p = 0, q = 1;  // result fraction p/q

        // Binary search on fraction value
        while (high - low > 1e-9) {
            double mid = (low + high) / 2.0;

            int count = 0;
            double best = 0.0;
            int i = 0;

            // Count fractions <= mid
            for (int j = 1; j < n; j++) {
                while (i < j && arr[i] <= mid * arr[j]) {
                    i++;
                }

                count += i;

                // Track maximum fraction <= mid
                if (i > 0) {
                    double val = (double)arr[i - 1] / arr[j];
                    if (val > best) {
                        best = val;
                        p = arr[i - 1];
                        q = arr[j];
                    }
                }
            }

            if (count < k)
                low = mid;
            else
                high = mid;
        }

        return {p, q};
    }
};



Not optimal O(n2)

class Solution {
public:
    static bool cmp(const pair<int,int>& a,const pair<int,int>& b){
        return (long double)a.first*b.second < (long double)a.second*b.first;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<pair<int,int>> frac;
        vector<int> res;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                frac.push_back({arr[i],arr[j]});
            }
        }
        sort(frac.begin(),frac.end(),cmp);
        return { frac[k-1].first, frac[k-1].second };
    }
};
