/* Suman Kumar*/

// #ifdef LOCAL
// #include "bits/stdc++.h"
// #else
// #include <bits/stdc++.h>
// #endif


// find sum of distance of each node in tree from all other nodes

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <iterator>
#include <functional>
#include <limits>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
// template<class key, class value, class cmp = std::less<key>>
// using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define ii pair<lli,lli>
#define rep(i,a,b) for(lli i=a;i<=b;i++)
#define rrep(i,a,b) for(lli i=a;i>=b;i--)
#define sz(x) ((int)(x).size())

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x...)
#endif

typedef long long int lli;
typedef unsigned long long ulli;
typedef long double lld;

lli n;
vector<lli> g[100100];

lli indp[100100];
lli outdp[100100];
lli sz[100100];

void indfs( lli nn , lli pp ){
    indp[nn] = 0;
    sz[nn] = 1;

    for( auto v:g[nn] ){
        if( v != pp ){
            indfs(v, nn);
            sz[nn] += sz[v];
            indp[nn] += indp[v] + sz[v];
        }
    }
}

void outdfs( lli nn , lli pp ){
    if( nn == 1ll ){ // root
        outdp[nn] = 0;
    }else{
        outdp[nn]  = outdp[pp] + indp[pp] - (indp[nn] + sz[nn] ) + n - sz[nn];
    } 
    
    for( auto v:g[nn] ){
        if( v != pp ){
            outdfs(v, nn);
        }
    }
}

void solve(){
    cin >> n;

    for( lli i=0; i<n-1; i++ ){
        lli a, b;
        cin >> a >> b;
        g[b].push_back(a);
        g[a].push_back(b);
    }
}

signed main()
{
    fastio();
    lli _t=1ll; 
    // cin >> _t;
    // clock_t begin=clock();
    while(_t--)
    {
        solve();
    }
    // clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    // cerr << endl;
    // cerr << "Time: " << elapsed_secs  << endl;
    return 0;
}
