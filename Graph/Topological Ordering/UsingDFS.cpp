#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define rep(i,n) for(lli i=0;i<n;i++)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pob pop_back
lli mod=1e9+7;
vector<vector<int> > g;
vector<int> vis;
vector<int> top_or;
int n,m;

void dfs(int node)
{
    vis[node]=1;
    for(auto v:g[node])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }

    top_or.pb(node);

}
void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(lli i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    reverse(top_or.begin(), top_or.end());

    for(auto k:top_or)
    {
        cout << k <<" ";
    }

    cout << "\n";


}
