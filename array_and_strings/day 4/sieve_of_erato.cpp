//sieve of eratosthenes
  vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int p = 2; p*p <= n; p++) {
        if(is_prime[p]) {
            for(int multiple = p*p; multiple <= n; multiple += p)
                is_prime[multiple] = false;
        }
    }
    vector<int> primes;
    for(int i = 2; i <= n; i++)
        if(is_prime[i]) primes.push_back(i);
    return primes;
}



class Solution {
  public:
    vector<int> sieve(int n) {
        int l=2,r=n;
        vector<int> ar;
        if(n==1) return ar;
        while(l<=r){
            if(l==r){
                int f=0;
                for(int i=2;i<=(int)sqrt(l);i++){
                    if(l%i==0){
                        f=1;break;
                    }
                }
                if(!f) ar.push_back(l); 
            }
            else{
                int f=0;
                for(int i=2;i<=(int)sqrt(l);i++){
                    if(l%i==0){
                        f=1;break;
                    }
                }
                if(!f) ar.push_back(l); 
                
                f=0;
                for(int i=2;i<=(int)sqrt(r);i++){
                    if(r%i==0){
                        f=1;break;
                    }
                }
                if(!f) ar.push_back(r); 
            }
            l++;r--;
        }
        sort(ar.begin(),ar.end());
        return ar;
    }
};
