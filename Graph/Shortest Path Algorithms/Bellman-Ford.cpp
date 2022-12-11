#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define rep(i,n) for(lli i=0;i<n;i++)
#define ii pair<lli,lli>
#define F first
#define S second

vector<vector<ii> > g;
vector<lli> dist;
lli n, m,st;

void bellman()
{
	for(lli i=1;i<=n;i++)
	{
    	   for(auto v:g[i])
    	   {
        	dist[v.F]=min(dist[v.F],dist[i]+v.S);
    	   }
	}
}
void solve()
{
	cin >> n >> m >> st;
	g.resize(n+1);

	dist.assign(n+1,1e9);
	dist[st]=0;

	for(lli i=0;i<n;i++)
	{
    	for(int j=0;j<m;j++)
    	{
        	lli a,b,k;
        	cin >> a >> b >> k;
        	g[a].push_back({b,k});
        	g[b].push_back({a,k});
    	}
	}

	for(lli i=1;i<n;i++)
	{
    	bellman();
	}

	bool neg_cyc=0;

	for(lli k=1;k<n;k++)
	{
    	for(lli i=1;i<=n;i++)
    	{
        	for(auto v:g[i])
        	{
            	if(dist[v.F]>dist[i]+v.S){
                	neg_cycle=1;
                	break;
            	}
        	}
    	}
	}

}

// O(V*E)



