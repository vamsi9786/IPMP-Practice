https://leetcode.com/problems/trapping-rain-water/description/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Approach 1: Two Pointers [ O(n) O(1) ]

Algo: 
      Think of two walls trapping water.
            1. The shorter wall is always the limiting wall.
            2. If the left wall is shorter, no matter how tall the right wall eventually becomes, 
                the water level cannot exceed the left wall. So process the left side.
            3. If the right wall is shorter, the water level is limited by the right wall. So process the right side.

      For every index i, Water(i) = min(MaxLeft, MaxRight) - height[i] 
                  MaxLeft = tallest bar on the left , MaxRight = tallest bar on the right

class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
       int left=0,right=n-1;
       int ans=0;
       int leftMax=0,rightMax=0;
       while(left<right){
        if(height[left]<=height[right]){
            if(height[left]>=leftMax){
                leftMax=height[left];
            }
            else{
                ans+=leftMax-height[left];
            }
            left++;
        }
        else{
            if(height[right]>=rightMax){
                rightMax=height[right];
            }
            else{
                ans+=rightMax-height[right];
            }
            right--;
        }
       }
       return ans;
    }
};


Approach 2: Stack Approach [ O(n) O(n) ]

Algo: Maintain Decreasing Monotonic Stack.
      if larger ht appears then take it as right boundary and stk.top() has bottom and pop stk.top() and then new stk.top() has left boundary
      now width=right-left-1; i.e i-left-1; and ht=min(left,right)-bottom and add to ans

class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
       int ans=0;
       stack<int> stk;
       for(int i=0;i<n;i++){
        while(!stk.empty() && height[i]>height[stk.top()]){
            int bottom=stk.top();
            stk.pop();
            if(stk.empty()) break;
            int left=stk.top();
            int width=i-left-1;
            int ht=min(height[left],height[i])-height[bottom];
            ans+=width*ht;
        }
        stk.push(i);
       }
       return ans;
    }
};
