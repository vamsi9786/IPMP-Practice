https://leetcode.com/problems/min-stack/description/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
    MinStack() initializes the stack object.
    void push(int value) pushes the element value onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.

Algo:
      DS: Two Stacks:  1. stack<int> st;      // actual elements
                       2. stack<int> minSt;   // minimum till current position
      fn: 1. push(x): Push into normal stack.
                      push into min stack  if( minSt.empty() || val <= minSt.top() ) i.e empty minstack or if curr val is new min
          2. Pop():  pop from min stack if ( stk.top() == minSt.top() ) i.e top of min stack === top of normal stack.
                     pop from normal stack.
          3. top(): return top of normal stack
          4. getMin(): return top of min stack


class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;

public:
    MinStack() {
    }
    
    void push(int value) {
        stk.push(value);
        if(min_stk.empty() || min_stk.top()>=value) min_stk.push(value);
    }
    
    void pop() {
        if(stk.top()==min_stk.top()) min_stk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
