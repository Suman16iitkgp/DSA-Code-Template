/*
Given a simple graph, output the number of simple cycles in it. A simple cycle is a cycle with no repeated vertices or edges.
Input Format
The first line of input contains two integers n and m (1 ≤ n ≤ 20, 0 ≤ m) – respectively the number of vertices and edges of the graph. Each of the subsequent m lines contains two integers a and b, (1 ≤ a, b ≤ n, a ≠ b) indicating that vertices a and b are connected by an undirected edge. There is no more than one edge connecting any pair of vertices.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[20][(1<<20)];
bool isEdge[20][20];
int n, m;
int cur;

int dfs(int pos, int vis, int sz) {
    if(dp[pos][vis] != -1) {
        return dp[pos][vis];
    }
    int ans = 0;
    if(sz > 2 && isEdge[pos][cur]) {
        ans++;
    }
    for (int i = cur; i < n; ++i) {
        if((vis & (1<<i))) continue;
        if(isEdge[pos][i]) {
            ans += dfs(i, (vis | (1<<i)), sz+1);
        }
    }
    return dp[pos][vis]=ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        isEdge[a][b] = isEdge[b][a] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cur = i;
        memset(dp, -1, sizeof(dp));
        ans += dfs(i, (1<<i), 1);
    }
    cout << ans/2;
    return 0;
}