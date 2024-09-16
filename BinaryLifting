// Consistency is the key.
// Even if you have started late you can still achieve many things.
// Always upsolve the problem after the contest.
// Don't give up without even trying the problem.

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
#define endl "\n"
const int mod = (int )1e9 + 7;

void build(int node, int par, vector<vector<int> >&up, vector<int> *adj){

    up[node][0] = par;

    for(int i=1;i<25;i++){
        int oneLevel = up[node][i-1];
        if(oneLevel == -1) break; 
        int par = up[oneLevel][i-1];
        if(par == -1) break;
        up[node][i] = par;
    } 

    for(auto itr : adj[node]){
        build(itr, node, up, adj);
    }
}

int binaryLifting(int node, int k, vector<vector<int> > &up){
    
    for(int i=30;i>=0;i--){
        if(k & (1<<i)){
            node = up[node][i];
            if(node == -1) return node;
        }
    }
    return node;
}

void test_cases(){
    // cout << "here";
    int n, q;
    cin >> n >> q;

    vector<int> adj[n+1];

    for0(i, n-1){
        int ele;
        cin >> ele;
        adj[ele].push_back(i+2);
    }

    vector<vector<int>> up(n + 1, vector<int> (30, -1));
    build(1, -1, up, adj);

    for0(i, q){
        int node, k;
        cin >> node >> k;
        // cout << node;

        cout << binaryLifting(node, k, up) << endl;
    }
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
