#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define ii pair<int,int>
#define S second
#define F first

vector<ii> g[100100];
int m, n;
int dist[100100];
int vis[100100];

void dijkstra(int sc)
{
    priority_queue<ii> pq;
    for(int i=1;i<=n;i++)
    {
        dist[i]=1e18;
        vis[i]=0;
    }

    dist[sc]=0;
    pq.push({-0,sc});

    while(!pq.empty())
    {
        ii fs=pq.top();
        pq.pop();
        if(vi[fs.S])continue;
        vis[fs.S]=1;

        for(auto v:g[fs.S])
        {
            int nh=v.F;
            int w=v.S;

            if(dist[nh]>dist[fs.S]+ w)
            {
                dist[nh]= dist[fs.S]+w;
                pq.push({-dist[nh],nh});
            }
        }

    }

}
void solve()
{
    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a,b,k;
            cin >> a >> b >> k;
            g[a].push_back({b,k});
            g[b].push_back({a,k});
        }
    }

    dijkstra(1);

}

// O((E+V)logE)
