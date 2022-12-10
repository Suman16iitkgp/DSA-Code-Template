vector<vector<int> > g;
int n,m;
int in[100100],out[100100];
int time=0;
void dfs(int node,int par)
{
	in[node]=out[node]=time++;

	for(auto v:g[node])
	{
    	if(v!=par)
    	{
        	dfs(v,node);
        	out[node]=time++;
    	}
	}

	return;
}
void solve()
{
	// Take g array,n,m
	int u,v;
	cin>>u>>v;

	dfs(1,-1);

	if(in[u]<=in[v] && out[u]>=out[v]){
    	cout<<"YES\n";

    	// U is an ancestor of V
	}else{
    	cout<<"NO\n";
	}
}
