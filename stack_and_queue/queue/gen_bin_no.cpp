https://www.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1

Given a number n. The task is to generate all binary numbers with decimal values from 1 to n.

  Algorithm:
      1. Initialize queue with "1"
      2. Repeat n times:
          Take front element
          Add to result
          Push:
            curr + "0"
            curr + "1"

Intution:   Binary numbers are formed like a tree
        1
       / \
     10   11
    / \   / \
 100 101 110 111

  class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> res(n);
        queue<string> q;
        q.push("1");
        for(int i=0;i<n;i++){
            string curr=q.front();
            q.pop();
            
            res[i]=curr;
            q.push(curr+"0");
            q.push(curr+"1");
        }
        return res;
    }
};
