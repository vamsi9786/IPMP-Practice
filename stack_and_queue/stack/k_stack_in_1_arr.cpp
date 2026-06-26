https://www.geeksforgeeks.org/problems/implement-k-stacks-in-an-array/1

You are given two integers n and k. Your task is to implement a class kStacks that uses a single array of size n to simulate k independent stacks.
The class should support the following operations:

push(x, i) – Push element x into the i-th stack.
pop(i) – Pop the top element from the i-th stack and return it. Return -1 if it is empty.
There will be a sequence of q queries queries[][]. The queries are represented in numeric form:

1 x i: Call push(x, i)
2 i:  Call pop(i)
The driver code will process the queries, call the corresponding functions, and print the outputs of pop(i) operations.
You only need to implement the above two functions.


Algo:
    DS used: 1. arr[] = Stores actual values.
             2. top[] = Stores top index of every stack.
             3. next[] = 2 uses: before allocated, stores next free idx and after allocated, stores next ele in stack i.e top[i] 
    fn: 1. push(x,i): 1. take next freeTop as idx=freeTop and update freeTop as freeTop=next[idx]
                      2. store ele in arr arr[idx]=x;
                      3. update next[idx] and top[i] as next[idx]=top[i] and top[i]=idx;
        
        2. pop(i):  1. take idx as popped ele i.e idx=top[i] and update top as top[i]=next[idx];
                    2. update freeTop and next[idx] as next[idx]=freeTop and freeTop=idx;
                    3. return arr[idx]

class kStacks {
    // main array to store elements
    int *arr;
    int *top;
    int *next;
    int freeTop;
    int n,k;
    
  public:
    kStacks(int n, int k) {
        this->n=n;
        this->k=k;
        
        arr=new int[n];
        top=new int[k];
        next=new int[n];
        
        for(int i=0;i<k;i++) top[i]=-1;
        for(int i=0;i<n;i++) next[i]=(i==n)?-1:i+1;
        freeTop=0;
    }

    void push(int x, int i) {
        // push element x into stack i
        if(freeTop==-1) return;
        
        int idx=freeTop;
        freeTop=next[idx];
        
        arr[idx]=x;
        
        next[idx]=top[i];
        top[i]=idx;
    }

    int pop(int i) {
        // pop element from stack i
        if(top[i]==-1) return -1;
        
        int idx=top[i];
        top[i]=next[idx];
        
        next[idx]=freeTop;
        freeTop=idx;
        
        return arr[idx];
    }
};
