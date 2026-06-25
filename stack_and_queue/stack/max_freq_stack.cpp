https://leetcode.com/problems/maximum-frequency-stack/description/

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:
    FreqStack() constructs an empty frequency stack.
    void push(int val) pushes an integer val onto the top of the stack.
    int pop() removes and returns the most frequent element in the stack.
    If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

Algo: 
    Idea: Instead of storing elements in one stack, maintain one stack for each frequency.
    DS Used: unordered_map<int,int> freq; === Frequency of every number
             unordered_map<int, stack<int>> group; === Stack for every frequency
             int maxFreq; === Maximum frequency present
    fn: 1. Push(x) : Increase frequency , Push into that freq stack , update maxFreq
            push(5): freq[5]++; if freq becomes 3; group[3].push(5); maxFreq = max(maxFreq,3);
        2. Pop(): Always pop from group[maxFreq]; Decrease ele freq; if maxFreq grp becomes empty dec maxFreq ; return x;
            pop(): x=group[maxFreq].top(); group[maxFreq].pop(); freq[x]--; if(group[maxFreq].empty()) maxFreq--; return x;




class FreqStack {
private:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int maxFreq;
public:
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        freq[val]++;
        int f=freq[val];
        group[f].push(val);
        maxFreq=max(maxFreq,f);
    }
    
    int pop() {
        int val=group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if(group[maxFreq].empty()) maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
