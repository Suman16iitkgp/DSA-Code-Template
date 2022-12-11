// Find the size of the tree

lli n;
vector<lli> g[mx];
lli par[mx];
lli dist[mx];
lli sz[mx];

void dfs(lli nn, lli pp, lli dd)
{
    par[nn]=pp;  // Parent od node
    dist[nn]=dd; // Distance of node from starting node
    sz[nn]=1;    // Size of Subtree
    for(auto v:g[nn] ){
        if(v!=pp){
            dfs(v,nn,dd+1);
            sz[nn]=sz[nn]+sz[v];
        }
    }
}