#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define rep(i,n) for(lli i=0;i<n;i++)
#define ii pair<int,int>
#define F first
#define S second
lli mod=1e9+7;

int n,m;
vector<string> arr;
vector<vector<int>> dist;
vector<vector<ii> > back;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool check(ii cur){
    if(cur.F>=0&&cur.F<n&&cur.S>=0&&cur.S<m&&arr[cur.F][cur.S]!='#')return 1;
    else return 0;
}
void bfs(ii st)
{
    dist=vector< vector < int > >(n,vector<int>(m,1e8));
    back=vector< vector < ii > >(n,vector<ii>(m,{-1,-1}));
    queue<ii> q;
    q.push(st);
    dist[st.F][st.S]=0;

    while(!q.empty())
    {
        ii cur=q.front();
        q.pop();

        for(int k=0;k<4;k++)
        {
            ii newCur={cur.F+dx[k], cur.S+dy[k]};
            if(check(newCur) && dist[newCur.F][newCur.S]>dist[cur.F][cur.S]+1)
            {
                dist[newCur.F][newCur.S]=dist[cur.F][cur.S]+1;
                back[newCur.F][newCur.S]=cur;
                q.push(newCur);

     } }
}
void solve()
{

    cin>>n>>m;
    arr.resize(n);

    ii st,en;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='S')
            {
                st={i,j};
            }

            if(arr[i][j]=='E')
            {
                en={i,j};
            }
        }
    }

    bfs(st);
    cout<<dist[en.F][en.S]<<"\n";
    
    vector<ii> path;

    ii last=en;
    while(last!=make_pair(-1,-1))
    {
        path.push_back(last);
        last = back[last.F][last.S];
    }

    reverse(path.begin(),path.end());
    for(auto v:path){
        cout<<v.F<<" "<<v.S<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
