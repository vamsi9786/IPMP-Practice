Segmented Sieve Algorithm Steps

1.  Compute limit:    Calculate limit = √n (square root of the upper bound).
  
2.  Sieve small primes:    Use the normal Sieve of Eratosthenes to find all primes ≤ limit.

3.  Create segment array:
      Make a boolean array of size n - m + 1, initialized to true.
      This array represents numbers in [m, n].

4.  Mark multiples:
      For each small prime p:
              Calculate the first multiple of p in [m, n]:      start = max(p*p, ceil(m/p) * p)
              Mark all multiples of p in the segment as not prime.
  
5.  Handle special case:  If m = 1, mark it as not prime.
6.  Output primes:  All numbers in the segment array that remain true are primes.


Step 1: Sieve up to √n → small primes
Step 2: Create segment [m, n]
Step 3: For each small prime p, mark all multiples in [m, n]
Step 4: Special case: 1 is not prime
Step 5: Print remaining numbers → primes


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		cin>>m>>n;
		
		long long limit=sqrt(n)+1;
		
		vector<bool> small_prime(limit+1,true);
		small_prime[0]=small_prime[1]=false;
		
		for(long long i=2;i*i<=limit;i++){
			if(small_prime[i]){
				for(long long j=i*i;j<=limit;j+=i){
					small_prime[j]=false;
				}
			}
		}
		
		vector<long long> primes;
		for(long long i=2;i<=limit;i++){
			if(small_prime[i]) primes.push_back(i);
		}
		
		//segment m,n
		vector<bool> is_prime(n-m+1,true);
		
		for(long long p:primes){
			long long st=max(p*p,((m+p-1)/p)*p);
			for(long long j=st;j<=n;j+=p){
				is_prime[j-m]=false;
			}
		}
		
		if(m==1) is_prime[0]=false;
		
		for(long long i=0;i<=n-m;i++){
			if(is_prime[i]) cout<<i+m<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
