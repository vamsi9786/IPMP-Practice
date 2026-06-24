https://leetcode.com/problems/largest-rectangle-in-histogram/description/

Given an array of integers heights representing the histogram bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Intution: How far the present bar can be extended to left and right

ex: [ 2, 1, 5, 6, 2, 3]
  2-> can be from left to before 1
  1-> from left to right
  5-> from 5 to before 2
  6-> from 6 to before 2
  2-> after 1 to right
  3-> from 3 to right

Algortihm:
      1. use monotonic stack (We keep bars in increasing height order ). 
          When a smaller bar appears, it determines the right boundary for all taller bars before it.
      2. find left smallest and right smallest and find max area of all bars
      3. keep heights in increasing order if smaller ele is seen then
                (Right boundary = current index) and (Left boundary = stack top)
      4. Why this works..? 
              The stack ensures: bars are increasing and So whenever a smaller bar appears: all larger bars before it must end here
      5. we keep final ele as 0 i.e n+1 ele (ele at idx 'n') which makes sures all ele poped out (stack is empty).

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n=heights.size();
        int ans=0;
        for(int i=0;i<=n;i++){
          int currH=(i==n)?0:heights[i];
          while(!stk.empty() && currH < heights[stk.top()] ){
            int h=heights[stk.top()];
            stk.pop();
            int w;
            if(stk.empty()) w=i;
            else w=i-stk.top()-1;
            ans=max(ans,h*w);
          }
          stk.push(i);
        }
      return ans;
    }
};
