#include<bits/stdc++.h>
using namespace std;
#define int long long 
using ii = pair<int,int>;
#define F first 
#define S second 

/*
You are given a weighted tree consisting of N vertices. Vertices ui and vi are connected by an edge with weight wi.
Let's define the K-coloring of the tree as an assignment of exactly K colors to each vertex so that each color is used no more than two times. 
You can assume that you have infinitely many colors available. We say that an edge is saturated in the given K-coloring if its endpoints s
hare at least one color (i.e. there exists a color that is assigned to both endpoints).
Let's also define the value of a K-coloring as the sum of weights of saturated edges.
Please calculate the maximum possible value of a K-coloring of the given tree.

*/

int dp[1000001][2];
vector<vector<ii>> g;
int n,k;
void dfs(int node,int par){
    dp[node][0]=0;
    dp[node][1]=0;
    int no_edge_taken_res = 0;
    vector<int> delta;
    for(auto v:g[node]){
        if(v.F!=par){
            dfs(v.first,node);
            no_edge_taken_res += dp[v.first][0];
            delta.push_back(v.second + dp[v.first][1] - dp[v.first][0]);
        }
    }
    sort(delta.begin(),delta.end());
    delta.push_back(0);
    reverse(delta.begin(),delta.end());
    int edges_taken_res = no_edge_taken_res;
    for(int x=0;x<delta.size();x++){
        edges_taken_res += delta[x];
        if(x==k){
            dp[node][0] = max(dp[node][0],edges_taken_res);
            break;
        }
        dp[node][0] = max(dp[node][0],edges_taken_res);
        dp[node][1] = max(dp[node][1],edges_taken_res);
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        g.resize(n+1);
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<'\n';
        g.clear();
    }
}