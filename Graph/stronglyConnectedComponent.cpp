#include<bits/stdc++.h>
using namespace std;

class StronglyConnectedComponent {
private:
    int n;
    vector<vector<int>> g, gRev;
    vector<int> vis, scc;
    /*
        g - given graph
        gRev - graph with reversed edges
    */
    
    void dfs(int node, stack<int> &sk){
        vis[node] = 1;
        for( auto v:g[node] ){
            if( !vis[v] ){
                dfs(v, sk);
            }
        }
        sk.push( node );
    }
    
    void dfs2(int node, int curScc){
        scc[node] = curScc;
        vis[node] = 1;
        
        for( auto v:gRev[node] ){
            if( !vis[v] ){
                dfs2(v, curScc);
            }
        }
    }
public:
    StronglyConnectedComponent (int _n, vector<vector<int>> graph, vector<vector<int>> graphRev){
        n = _n;
        g = graph;
        gRev = graphRev;
        vis = vector<int> (n+1, 0);
        scc = vector<int> (n+1);
    }
    
    void findSCC(){
        stack<int> sk;
        for( int i=1; i<=n; i++ ){
            if( !vis[i] ){
                dfs(i, sk);
            }
        }
        
        
        int curScc = 0;
        vis.assign( n+1, 0 );
        while( !sk.empty() ){
            int cur = sk.top();
            sk.pop();
            
            if( !vis[cur] ){
                curScc++;
                dfs2(cur, curScc);
            }
        }
        
        cout << curScc << "\n";
        for( int i=1; i<=n; i++ ){
            cout << scc[i] << " ";
        }
        cout << "\n";
        
        
    }
};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n+1);
    vector<vector<int>> gRev(n+1);
    
    for( int i=1; i<=m; i++ ){
        int a, b;
        cin >> a >> b;
        g[a].push_back( b );
        gRev[b].push_back( a );
    }
    
    StronglyConnectedComponent stronglyConnectedComponent = StronglyConnectedComponent(n, g, gRev);
    stronglyConnectedComponent.findSCC();
    
    return 0;
}