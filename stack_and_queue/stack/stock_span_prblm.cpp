https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

The stock span problem is a financial problem where we have a series of daily price quotes for a stock and 
we need to calculate the span of stock price for all days.You are given an array arr[] representing daily stock prices,
the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) 
for which the price of the stock is less than or equal to the price on day i. 
Return the span of stock prices for each day in the given sequence.


class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        vector<int> res(n,1);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()]<=arr[i]){
                stk.pop();
            }
            if(stk.empty()) res[i]=i+1;
            else  res[i]=i-stk.top();
            stk.push(i);
        }
        return res;
    }
};
