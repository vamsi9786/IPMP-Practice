https://www.geeksforgeeks.org/dsa/find-maximum-difference-between-nearest-left-and-right-smaller-elements/

Maximum difference between nearest left and right smaller elements

Given an array of integers, the task is to find the maximum absolute difference between the nearest left and the right smaller element of every element in the array. 
Note: If there is no smaller element on right side or left side of any element then we take zero as the smaller element. 
For example for the leftmost element, the nearest smaller element on the left side is considered as 0. 
Similarly, for rightmost elements, the smaller element on the right side is considered as 0.


[Expected Approach] Using Single Stack – O(n) Time and O(n) Space

int findMaxDiff(vector<int>& arr) {
    stack<int> st;
    int mxDiff = 0;
    int leftSmaller, rightSmaller;
    int n = arr.size();
    
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int ind = st.top();
            
            // rightSmaller element as arr[i]
            rightSmaller = arr[i]; 
            st.pop();
            
            // element present just below 
            // in the stack is the left smaller element
            if (!st.empty())
                leftSmaller = arr[st.top()]; 
            else
                leftSmaller = 0;
            mxDiff = max(mxDiff, abs(rightSmaller - leftSmaller));
        }
        if (st.empty())
        {
            st.push(i);
        }
        
        // avoid duplicates which are together
        else if (arr[st.top()] == arr[i])
        {
            continue; 
        }
        else
        {
            st.push(i);
        }
    }
    
    // element that are still present in the stack 
    // are those element whose right smaller element 
    // does not exist. so for these elements rightsmaller 
    // element will be 0 and the left smaller element 
    // will be element present just below in the stack.
    while(!stk.empty()){
        int ind = st.top();
        rightSmaller = 0;
        st.pop();
        if (!st.empty())
            leftSmaller = arr[st.top()];
        else
            leftSmaller = 0;
        mxDiff = max(mxDiff, abs(rightSmaller - leftSmaller));
    }
    return mxDiff;
}
