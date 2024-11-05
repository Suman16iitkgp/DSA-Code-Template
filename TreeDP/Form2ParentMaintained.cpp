#include<bits/stdc++.h>
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

/*
You are given a tree with n vertices and a positive number k. 
Find the number of distinct pairs of the vertices that have a distance of exactly k between them. Note that pairs (v, u) and (u, v) are considered to be the same pair.
The distance between two vertices of a tree is the length (in edges) of the shortest path between these vertices.


*/

lli n, k;
vector<lli> g[100010];
lli indp[100010][510];   // indp[i][k] No of nodes which is at distance of k units from i in subtree
lli outdp[100010][510];   // outdp[i][k] No of nodes which is at distance of k units and not part of subtree
void indfs(lli nn, lli pp)
{
    indp[nn][0] = 1;  // height with 1 itself

    for(auto ch:g[nn]){
        if(ch != pp){
            indfs(ch, nn);
            rep(i, 1, k){
                indp[nn][i] += indp[ch][i-1];
            }
        }
    }
}

void outdfs(lli nn, lli pp)
{
    if(pp != 0)
    {
        outdp[nn][1] = outdp[pp][0] + 1;
        rep(i, 2 , k)
        {
            // Adding outer part , siblings part and subtracting the contribution from subtree having root nn
            outdp[nn][i] = outdp[pp][i-1] + indp[pp][i-1] - indp[nn][i-2];   
        }
    }

    for(auto ch:g[nn])
    {
        if(ch != pp){
            outdfs(ch, nn);
        }
    }
}

void solve()
{
    cin >> n >> k;

    rep(i, 0, n)
    {
        g[i].clear();
        rep(j, 0, k+1){
            indp[i][j] = 0;
            outdp[i][j] = 0;
        }
    }
    rep(i, 1, n-1)
    {
        lli a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    indfs(1, 0);
    outdfs(1, 0);

    lli ans = 0;

    rep(i, 1, n)
    {
        ans += indp[i][k] + outdp[i][k];
    }

    ans /= 2;   // Undirected grap so divided by 2
    cout << ans <<"\n";

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    lli _t; 
    cin >> _t;
    // _t=1ll;

     clock_t begin=clock();
    while(_t--)
    {
        solve();
    }
     clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
    return 0;
}
