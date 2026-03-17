https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
Note: If a window does not contain a negative integer, then return 0 for that window


class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int> res;
        queue<int> q; // store indices of negatives

        int i = 0, j = 0;

        while(j < n){

            // include current element
            if(arr[j] < 0)
                q.push(j);

            // window size < k → expand
            if(j - i + 1 < k){
                j++;
            }

            // window size == k
            else{

                // answer
                if(!q.empty())
                    res.push_back(arr[q.front()]);
                else
                    res.push_back(0);

                // remove element going out of window
                if(!q.empty() && q.front() == i)
                    q.pop();

                i++;
                j++;
            }
        }

        return res;
    }

};



Method - II

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> res(arr.size()-k+1);
        queue<int> que;
        for(int j=0;j<arr.size();j++){
            if(arr[j]<0) que.push(j);
        }
        int i;
        for(i=0;i<=arr.size()-k;i++){
            if(!que.empty() && i<=que.front() && i+k>que.front()){
                res[i]=arr[que.front()];
                if(i==que.front()) que.pop();
            }
            else res[i]=0;
        }
        return res;
    }
};
