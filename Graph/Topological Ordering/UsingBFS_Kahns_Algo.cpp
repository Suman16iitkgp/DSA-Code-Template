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
vector<int> Ind; // Indegree Array
vector<int> top_or;
int n,m;
// 1 3 5 2 4 6 
void kahn()
{
    queue<int> q;
    
    for(int i=1;i<=n;i++)
    {
        if(Ind[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        top_or.pb(x);
        for(auto v:g[x])
        {
            Ind[v]--;
            if(Ind[v]==0)
            {
                q.push(v);

            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n+1);
    Ind.assign(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b); // edge from a to b
        Ind[b]++;
    }

    kahn();

    for(auto k:top_or)
    {
        cout << k-1 <<" ";
    }

    cout << "\n";


}



