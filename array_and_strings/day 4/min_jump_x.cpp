problem: Find the number of jumps to reach X in the number line from zero.
  Given an integer X. The task is to find the number of jumps to reach a point X in the number line starting from zero. 

1.  If you have always jumped in the right direction then after n jumps you will be at the point p = 1 + 2 + 3 + 4 + ... + n.
2.  In any of these n jumps, if instead of jumping right, you jumped left in the kth jump (k<=n), you would be at point p - 2k.
3.  Moreover, by carefully choosing which jumps to go left and which to go right, after n jumps, you can be at any point 
    between n * (n + 1) / 2 and - (n * (n + 1) / 2) with the same parity as n * (n + 1) / 2.

#include <bits/stdc++.h>
using namespace std;

int getsum(int x){
    return (x * (x + 1)) / 2;
}

int countJumps(int n){
    n = abs(n);
    int ans = 0;

    while (getsum(ans) < n or (getsum(ans) - n) & 1)	ans++;
    return ans;
}
