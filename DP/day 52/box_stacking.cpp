https://www.geeksforgeeks.org/problems/box-stacking/1

You are given a set of some types of rectangular 3-D boxes, where the ith box has height, width, and length height[i], width[i], and length[i] respectively. 
You have to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box 
if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. 
Of course, you can rotate a box so that any side functions as its base. It is also allowable to use multiple instances of the same type of box. 
Your task is to complete the function maxHeight which returns the height of the highest possible stack so formed.

Note: Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.

Algo: 1. generate all possibilites (all rotations) ==> and push into boxes (h,max(l,w),min(l,w)) and (l,max(h,w),min(h,w)) and (w,max(l,h),min(l,h)).
      2. sort based on area
      3. do LIS

class Solution {
  public:
    /*The function takes an array of heights, width and
    length as its 3 arguments where each index i value
    determines the height, width, length of the ith box.
    Here n is the total no of boxes.*/
    struct box{
        int h,l,w;
    };
    
    //sort based on base area
    static bool cmp(const box& b1,const box& b2){
        return b1.l*b1.w > b2.l*b2.w;
    }
    
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // Your code here
        int n=height.size();
        vector<box> boxes;
        
        for(int i=0;i<n;i++){
            int h=height[i];
            int w=width[i];
            int l=length[i];
            
            boxes.push_back({h,max(l,w),min(l,w)});
            boxes.push_back({l,max(h,w),min(h,w)});
            boxes.push_back({w,max(h,l),min(h,l)});
        }
        
        sort(boxes.begin(),boxes.end(),cmp);
        
        int sz=boxes.size();
        vector<int> dp(sz);
        int ans=0;
        
        for(int i=0;i<sz;i++){
            dp[i]=boxes[i].h;
            for(int j=0;j<sz;j++){
                if(boxes[j].l>boxes[i].l && boxes[j].w>boxes[i].w){
                    dp[i]=max(dp[i],dp[j]+boxes[i].h);
                }
            }
            ans=max(dp[i],ans);
        }
        
        return ans;
    }
};


