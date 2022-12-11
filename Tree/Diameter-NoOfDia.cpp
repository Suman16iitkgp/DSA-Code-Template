#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define rep(i,n) for(lli i=0;i<n;i++)
lli n;
vector<vector<lli> > g;
lli par[200100];
lli dist[200100];
lli target=-1;
lli cnti;
void dfs(lli nn, lli pp, lli dd)
{
    par[nn]=pp;
    dist[nn]=dd;

    if(dd==target){
        cnti++;
    }
    for(auto v:g[nn])
    {
        if(v != pp){
            dfs(v,nn,dd+1);
        }
    }
} 
void solve()
{
    cnti=0;
    cin>>n;
    g.resize(n+1);

    if(n==1)
    {
        cout<<1<<"\n";
        return;
    }

    for(lli i=0;i<n-1;i++)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,0,0);
    lli snn=1;
    lli snl=0;
    for(lli i=1;i<=n;i++)
    {
        if(dist[i]>snl){
            snn=i;
            snl=dist[i];
        }
    }

    dfs(snn,0,0);

    lli tnn=snn;
    lli tnl=0;

    
    for(lli i=1;i<=n;i++)
    {
        if(dist[i]>tnl){
            tnn=i;
            tnl=dist[i];    // Diameter of Tree
        }
    }

    // cout<<tnl;
    vector<lli> cent;
    vector<lli> path;
    lli tpc=tnn;
    while(tpc!=0){
        path.push_back(tpc);
        tpc=par[tpc];
    }

    lli rd=path.size();
    if(rd&1){
        cent.push_back(path[rd/2]);   // Center of Tree
        // cout<<cent.size();
        vector<lli> res;
        for(auto it:g[cent[0]]){
            cnti=0;
            target=tnl/2-1;
            dfs(it,cent[0],0);

            // cout<<cnt1<<"\n";
            res.push_back(cnti);
        }  
        lli sum1=0,sum2=0;
        for(lli i=0;i<res.size(); i++)
        {
            sum1+=res[i];
            sum2+= res[i]*res[i];
        }

        lli ans= (sum1*sum1 - sum2)/2;
        cout<<ans<<"\n";

    }else{
        cent.push_back(path[rd/2]);
        cent.push_back(path[rd/2-1]);
        vector<lli> res3;
        for(lli i=0;i<2;i++)
        {
            lli cnt2=0;
            target=(tnl-1) /2;

            cnti=0;
            dfs(cent[i],cent[i^1],0);
            
            res3.push_back(cnti);
        }
        lli ans2=res3[0]*res3[1];
        cout<<ans2<<"\n";
    }