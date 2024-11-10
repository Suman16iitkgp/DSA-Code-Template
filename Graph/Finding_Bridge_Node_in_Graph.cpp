vector<int> vis;
vector<int> top_or;
vector<vector<int> > g;
int n,m;
int vis[100100];
int tin[100100],low[100100];
int time=0;
set<ii> st; 
void dfs(int nd,int par)
{
    tin[nd]=low[nd]=time++;
    vis[nd]=1;

    for(int v:g[nd])
    {
        if(v==par)
        {
            continue;
        }
        if(vis[v]){
            // Backward edge
            low[nd]=min(low[nd],tin[v]);
        }
        dfs(v,nd);
        low[nd]=min(low[nd], low[v]);

        if(low[v]>tin[nd]){
            bridge.insert({u,v});
        }
    }
}

