// The Function to calculate the power of a function in O(log(n)) time and space using Binary Exponentiation.............................

    long long power(int N,int R)
    {
       //Your code here
        if(R == 0) return 1;
        long long half = power(N, R/2);
        long long ans = (half * half)%mod;
        if(R%2) ans = (ans * N)%mod;
        return ans;
    }
