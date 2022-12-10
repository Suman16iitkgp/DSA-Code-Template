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
int n,m;
vector<ii> g[100100]; // Another way to define
int dist[100100];

void BFS01(int st)
{
    
    for(int i=1;i<=n;i++)
    {
        dist[i]=1e8;
    }

    deque<int> dq;
    dq.pb(st);
    dist[st]=0;

    while(!dq.empty())
    {
        int xx=dq.front();
        dq.pop_front();
        for(auto v:g[xx])
        {
            int ng=v.first;  // neighbour
            int wt=v.second  // weight

            if(dist[ng]>dist[xx]+wt)
            {
                dist[ng]=dist[xx]+wt;

                if(wt==0)
                {
                    dq.push_front(ng);
                }else
                {
                    dq.pb(ng);
                }

            }
        }
    }

}

void solve()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }

    int sc,en;
    cin >> sc >> en;
    BFS01(sc);

    cout << dist[en] << "\n";    // From source to end

}
