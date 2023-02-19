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
