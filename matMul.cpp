// A program for multiplication of square matrix

v2i matrixMul(v2i& a, v2i & b){
    int n = a.size();
    v2i ans(n, vi (n, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                ans[i][j] = (ans[i][j] + ((a[i][k] * b[k][j])%mod))%mod;
    return ans;
}
