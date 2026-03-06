Given 2 integers A and B and an array of integers C of size N. Element C[i] represents the length of ith board.
 You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of the board.

Calculate and return the minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of the board.
 NOTE: 
 1. 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
 2. A painter will only paint contiguous boards. This means a configuration where painter 1 paints boards 1 and 3 but not 2 is invalid.

 Return the ans % 10000003.

Algorithm
    1.  Low = length of the largest board (a painter must at least paint one full board)
        High = sum of all board lengths (one painter paints everything)
    2.  Can we assign boards to ≤ A painters such that each painter paints contiguous boards and no painter paints more than mid total board length?
          How to check:
                Start with painter 1
                Add boards sequentially
                If adding a board exceeds mid, assign a new painter
                If painters exceed A, return false
                If all boards are assigned, return true
    3.  Binary search repeat untill low==high initial low=max(C[i]) and high=sum of all C[i]. and mid=low+(high-low)/2;


bool willpaint(int a,vector<int> &c,long long m){
    long long curr=0;
    int pc=1;
    for(int t:c){
        if(t > m) return false;
        if((curr+t)>m){
            pc++;
            curr=t;
            if(pc>a) return false;
        }
        else{
            curr+=t;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    long long mod=10000003;
    
    int n=C.size();
    long long low=0,high=0;
    for(int i=0;i<n;i++){
        low=max(low,(long long)C[i]);
        high+=(long long)(C[i]);
    }
    
    while(low<high){
        long long mid=low+(high-low)/2;
        if(willpaint(A,C,mid)){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    long long res=(low%mod)*(B%mod);
    return res%mod;
}
