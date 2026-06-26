https://www.geeksforgeeks.org/problems/implement-k-queues-in-a-single-array/1

You are given two integers n and k. Your task is to implement a class kQueues that uses a single array of size n to simulate k independent queues.

The class should support the following operations:

enqueue(x, i) → Adds the element x into the i-th queue.
dequeue(i) → Removes the front element from the i-th queue and returns it. Returns -1 if the queue is empty.
isEmpty(i) → Returns true if i-th queue is empty, else return false.
isFull() → Returns true if the array is completely full and no more elements can be inserted, otherwise false.

There will be a sequence of q queries represented as:

1 x i : Call enqueue(x, i)
2 i : Call dequeue(i)
3 i : Call isEmpty(i)
4 : Call isFull()

The driver code will process the queries, call the corresponding functions, and print the results of dequeue, isEmpty, and isFull operations.
You only need to implement the above four functions.

//Similar to k-stack in 1 arr
Algo:
    DS used: 1. arr[] = Stores actual values.
             2. front[] = Stores front index of every queue.
             3. rear[] = Stores front index of every queue.
             4. next[] = 2 uses: before allocated, stores next free idx and 
                                 after allocated, stores (next ele in queue if not end ele ) or (if end of queue i.e -1) 
             5. freeSpot = Stores next avail spot i.e idx for storing incoming ele

    fn: 1. enqueue(x,i):  1. take next freeSpot as idx=freeSpot and update freeTop as freeSpot=next[idx]
                          2. if(empty queue) update front as front[i]=idx;
                             else (not empty) update next of rear as next[rear[i]]=idx;
                          3. store ele in arr arr[idx]=x; and  update next[idx] as -1 
                          4. update rear of queue as rear[i]=idx;
        
        2. pop(i):  1. take idx as popped ele i.e idx=front[i] and update front as front[i]=next[idx];
                    2. if(front[i]==-1) update rear as rear[i]=-1;
                    2. update freeSpot and next[idx] as next[idx]=freeSpot and freeSpot=idx;
                    3. return arr[idx]


class kQueues {
    private:
        int* arr;
        int* front;
        int* rear;
        int* next;
        
        int freeSpot;
        int n,k;

  public:
    kQueues(int n, int k) {
        // Initialize your data members
        this->n=n;
        this->k=k;
        
        freeSpot=0;
        
        arr=new int[n];
        front=new int[k];
        rear=new int[k];
        next=new int[n];
        
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        
        for(int i=0;i<n-1;i++) next[i]=i+1;
        next[n-1]=-1;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if(isFull()) return;
        
        int idx=freeSpot;
        freeSpot=next[idx];
        
        if(front[i]==-1){
            front[i]=idx;
        }
        else{
            next[rear[i]]=idx;
        }
        next[idx]=-1;
        rear[i]=idx;
        arr[idx]=x;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(isEmpty(i)) return -1;
        
        int idx=front[i];
        front[i]=next[idx];
        
        if(front[i]==-1) rear[i]=-1;
        
        next[idx]=freeSpot;
        freeSpot=idx;
        
        return arr[idx];
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return front[i]==-1;
    }

    bool isFull() {
        // check if array is full
        return freeSpot==-1;
    }
};
