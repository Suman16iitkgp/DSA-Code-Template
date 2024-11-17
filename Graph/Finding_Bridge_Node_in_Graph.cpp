vector<int> vis;
vector<int> top_or;
vector<vector<int> > g;
int n,m;
int vis[100100];
int tin[100100],low[100100];
int time=0;
set<ii> st; 
void dfs(int u,int par)
{
    tin[u]=low[u]=time++;
    vis[u]=1;

    for(int v:g[u])
    {
        if(v==par)
        {
            continue;
        }
        if(vis[v]){
            // Backward edge
            low[u]=min(low[u],tin[v]);
        }else{
            dfs(v,u);
            low[u]=min(low[u], low[v]);
            if(low[v]>tin[u]){
                bridge.insert({u,v});
            }
        }
        

        
    }
}

