int maxArea(int* height, int heightSize) {
    int left=0,right=heightSize-1;
    int maxar=0;
    while(left<right){
        int min=(height[left]<height[right])?height[left]:height[right];
        int area=abs(right-left)*min;
        if(area>maxar) maxar=area;
        if(height[left]<height[right]) left++;
        else right--;
    }
    return maxar; 
}
