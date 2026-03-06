/*
    x + x+1 + x+2 + ------ + x+(k-1)  //length k
    ==> kx + (k-1)*k/2 == n (which should be equal to n)
    
    ==> x = (n - (k-1)*k/2)/k  
    (x is a postive integer so)
    ==> (n - (k-1)*k/2) should be divisible by k and >0

    calc k_max:
    ==> n - (k-1)*k/2 >0
    ==> 2n > k^2 - k ==> (k^2 - k - 2n) < 0
    ==> k < (1+sqrt(1+8*n))/2
*/

#include <math.h>
typedef long long ll;
int consecutiveNumbersSum(int n) {
    int c=0,k_max;
    k_max=(int) (1+sqrt(1+8*(ll)n))/2;
    for(int k=1;k<=k_max;k++){
        int num= n - (ll)(k*(k-1)/2);
        if(num==0) break;
        if(num%k ==0) c++;
    }
    return c;
}
