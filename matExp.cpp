// a program to find out the sum of gp using the matrix exponentiation technique.
// This technique is used when the next term in a series is dependent on the previous term.
//Like finding out sum of G.P or A.P

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(a) a.begin(),a.end()
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define rloop(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define nd second
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vii vector<pi>
#define v2i vector<vi>
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vi, greater<int> >
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl 
#define pb push_back
int mod = (int )1e9 + 7;

v2i matrixMul(v2i& a, v2i & b){
    int n = a.size();
    v2i ans(n, vi (n, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                ans[i][j] = (ans[i][j] + ((a[i][k] * b[k][j])%mod))%mod;
    return ans;
}

v2i matExp(v2i mat,int pow){
    if(pow == 1) return mat;
    int n = mat.size();
    v2i ans(n , vi (n, 0));
    for(int i=0;i<n;i++) ans[i][i] = 1;
    if(pow == 0) return ans;
    
    if(pow%2) ans = matrixMul(ans, mat);
    v2i temp = matExp(mat, pow/2);
    temp = matrixMul(temp, temp);
    ans = matrixMul(ans, temp);
    return ans;
}

void test_cases(){
    int a, x, m;
    cin >> a >> x >> m;
    mod = m;

    v2i mat(2, vi (2, 0));
    mat[0][0] = a;
    mat[1][0] = a;
    mat[1][1] = 1;
    v2i curr = matExp(mat, x - 1);
    cout << (curr[1][0] + curr[1][1])%mod << endl;
}

signed main(){
#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif


    ll t = 1;
    // cin >> t;
    while(t--){
        test_cases();
    }
    return 0;
}
