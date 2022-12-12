/* Suman Kumar*/

// #ifdef LOCAL
// #include "bits/stdc++.h"
// #else
// #include <bits/stdc++.h>
// #endif

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

void _print(lli t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ulli t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
lli gcd(lli a, lli b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
lli expo(lli a, lli b, lli mod) {lli res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
lli mminvprime(lli a, lli b) {return expo(a, b - 2, b);}
bool revsort(lli a, lli b) {return a > b;}
lli combination(lli n, lli r, lli m, lli *fact, lli *ifact) {lli val1 = fact[n]; lli val2 = ifact[n - r]; lli val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<lli> sieve(int n) {int*arr = new int[n + 1](); vector<lli> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
lli mod_add(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
lli mod_mul(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
lli mod_sub(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
lli mod_div(lli a, lli b, lli m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*--------------------------------------------------------------------------------------------------------------------------*/

lli n, m;
vector<pair< lli, ii > > edges;

vector<lli> pt, rk;

lli curSiz;

lli find( lli nn ){
    if( pt[nn] == nn ){
        return nn;
    }

    return pt[nn] = find(pt[nn]);
}

void merge( lli a, lli b ){
    lli aRt = find( a ) , bRt = find( b );

    if( aRt == bRt ){
        return;
    }

    if( rk[aRt] >= rk[bRt] ){
        rk[aRt] += rk[bRt];
        pt[bRt] = aRt;
    }else{
        rk[bRt] += rk[aRt];
        pt[aRt] = bRt;
    }
    curSiz--;
}

void solve(){
    cin >> n >> m;

    for( lli i=1; i<=m; i++ ){
        lli a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a,b}});
    }

    sort( edges.begin(), edges.end() );

    pt.resize(n+1);
    rk.resize(n+1);

    for( lli i=1; i<=n; i++ ){
        pt[i] = i;
        rk[i] = 1;
    }

    lli ans = 0;
    curSiz = n;
    for( lli i=1; i<=m; i++ ){
        lli xrt = find( edges[i-1].S.F ) , yrt = find( edges[i-1].S.S );
        if( xrt != yrt ){
            ans += edges[i-1].F;
            merge( edges[i-1].S.F, edges[i-1].S.S );
        }
    }

    if( curSiz == 1ll ){
        cout << ans << "\n";
    }else{
        cout << "IMPOSSIBLE\n";
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