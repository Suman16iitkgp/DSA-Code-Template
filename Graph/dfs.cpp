int n,m;
vector<vector<int> > g;
vector<int> vis;

void dfs(int node, int comp)
{
    //
    // Debugging
    cout << "NODE" << " " << node << " " << " COMP" << comp <<"\n";
    //
    
    vis[node]=comp;
    for(auto v:g[node])
    {
        if(!vis[v])
        {
            dfs(v,comp);
        }
    }
}


void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);

    for(lli i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int stComp=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]){
            stComp++;
            dfs(i,stComp);
        }
    }
}
