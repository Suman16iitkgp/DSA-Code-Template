// Knapsack Problem

#ifdef LOCAL
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;
using lli=long long int;
using ld=long double;
#define rep(i,a,b) for(lli i=a;i<=b;i++)
#define rrep(i,a,b) for(lli i=a;i>=b;i--)
#define ii pair<lli,lli>
#define F first
#define S second
#define mp make_pair
lli mod = 1e9+7; // Handle the negative part always when taking modulus
lli mult(lli a, lli b){lli ans = ( (a%mod)*(b%mod) ) % mod; return ans;}
lli sub(lli a, lli b){ lli ans = (a%mod - b%mod + mod) %mod; return ans;}
lli ad(lli a, lli b){lli ans = (a%mod + b%mod)%mod; return ans;}
lli xx[] = {0,1,0,-1};
lli yy[] = {1,0,-1,0};
lli gcd( lli a, lli b){
    if( a < b ) { swap( a, b ); }
    if( b == 0 ){ return a; }
    return gcd(b, a%b);
}

lli n, w;
vector<ii> vc;
lli dp[110][100010];

lli rec( lli id, lli wrem ){

    if( wrem < 0 ){
        return -1e17;
    }
    if( id == n ){
        return 0;
    }

    if( dp[id][wrem] != -1 ){
        return dp[id][wrem];
    }

    lli ans = max( rec(id+1, wrem - vc[id].F ) + vc[id].S , rec(id+1, wrem) );

    return dp[id][wrem] = ans;
}
void solve()
{
    cin >> n >> w;

    memset( dp, -1, sizeof(dp) );
    
    rep( i, 1, n ){
        lli a, b;
        cin >> a >> b;
        vc.push_back( {a, b} );
    }

    lli ans = rec(0, w);

    cout << ans << "\n";
}

 
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 

    lli _t; 
    // cin >> _t;
    _t=1ll;
 
    clock_t begin=clock();
    while(_t--)
    {
        solve();
    }
    clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cerr << "Time: " << elapsed_secs  << endl;
    return 0;
}