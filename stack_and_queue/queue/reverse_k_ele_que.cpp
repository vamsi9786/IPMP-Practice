https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, 
leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.
    enqueue(x) : Add an item x to rear of queue
    dequeue() : Remove an item from front of queue
    size() : Returns number of elements in queue.
    front() : Finds front item.


class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        int n=q.size();
        stack<int> stk;
        if(k>n) return q;
        for(int i=0;i<k;i++){
            stk.push(q.front());
            q.pop();
        }
        while(!stk.empty()){
            q.push(stk.top());
            stk.pop();
        }
        for(int i=0;i<n-k;i++){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};
