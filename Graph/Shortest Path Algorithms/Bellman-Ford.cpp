#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define rep(i,n) for(lli i=0;i<n;i++)
#define ii pair<lli,lli>
#define F first
#define S second

lli dist[404][404];
lli par[404][404];

void printPath(lli i, lli j)
{
    if(i!=j)printPath(i,par[i][j]);
    cout<<j<<"\n";
}
void solve()
{
    lli n,m;
    cin >> n >> m;

    for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<m;j++)
        {
            if(i!=j)dist[i][j]=1e9;
            // dist[i][j]=1e9; // For smallest Cycle
        }
    }

    for(lli i=0;i<m;i++)
    {
        lli a,b,c;
        cin >> a >> b >> c;
        dist[a][b]=min(dist[a][b],c);
        // dist[i][j]=c; // For smallest Cycle
    }

    for(lli i=0;i<n;i++)
    {
        for(lli j=0;j<n;j++)
        {
            par[i][j]=i;
        }
    }

    for(lli k=0;k<n;k++)
    {
        for(lli i=0;i<n;i++)
        {
            for(lli j=0;j<n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                // dist[i][j]= dist[i][j] | (dist[i][k] & dist[k][j]);  For Reachability
                
                // if(dist[i][j]>dist[i][k]+dist[k][j])  // For Parenting Node
                // {
                //     dist[i][j]=dist[i][k]+dist[k][j];
                //     par[i][j]=par[k][j]
                // }
            }
        }
    }

    // lli ans=1e9;   //For smallest Cycle

    // for(lli i=0;i<n;i++)
    // {
    //     ans=min(ans,dist[i][i]);
    // }
    // coût<<ans<<"\n";

    
    // if(ans<0)      // Negative Cycle Check
    // {
    //     cout<<"YES\n";
    // }else{
    //     cout<<"NO\n";
    // }
    

}

// O(V3)




Bellman-Ford Algorithm

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



