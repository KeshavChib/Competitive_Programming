// The Function to calculate the power of a function in O(log(n)) time and space using Binary Exponention.............................

long long power(int N,int R)
{
   //Your code here
    if(R == 0) return 1;
       
    long long ans = 1;
    long long know = power(N, R/2)%mod;
    if(R%2) ans = N;
    return (ans*((know*know)%mod))%mod;
}

// The function to calculate the combination in O(n) time and space........................................

int nCr(int n, int r){

    if(n == r) return 1;
    if(r > n) return 0;
    if(r == 0) return 1;
    vector<long long> fact(n+1);
    fact[0] = fact[1] = 1;
        
    for(int i=2;i<=n;i++) fact[i] = (fact[i-1] * i)%mod;
        
    int x = (power(fact[r], mod-2)%mod);  // inverse(r) = r ki power mod-2; 
    int nr = (power(fact[n-r], mod-2)%mod); 
        
    return (((fact[n] * x)%mod)*nr)%mod;
}
