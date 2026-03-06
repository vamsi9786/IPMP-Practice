/Method-1

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int l=nums.size();
        vector<int> a1(l/2+1),a2(l/2);
        sort(nums.begin(),nums.end());
        for(int i=0;i<l;i++){
            if(l%2==0){
                if(i<(l/2)) a1[i]=nums[i];
                else a2[i-(l/2)]=nums[i];
            }
            else{
                if(i<(l/2)+1) a1[i]=nums[i];
                else a2[i-(l/2)-1]=nums[i];
            }
        }
        int x=0,y=0;
        for(int i=0;i<l;i++){
            if(i%2==0) nums[i]=a1[x++];
            else nums[i]=a2[y++];
        }
    }
};

/ Method-2

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int l=nums.size();
        for(int i=1;i<l;i++){
            if( (i%2==0 && nums[i]>nums[i-1]) || (i%2==1 && nums[i]<nums[i-1])){
                swap(nums[i],nums[i-1]);
            }
        }
    }
};
    
