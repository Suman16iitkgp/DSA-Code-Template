struct prefix1D{
    vi base;
    void init(int n){base.resize(n);}
    void build(){
        for(int i=1;i<base.size();i++)
            base[i]+=base[i-1];
    }
    lli get(int l,int r){
        return base[r]-(l>0?base[l-1]:0);
    }
};
// O(N)

struct prefix2D{
    vector<vi> base;
    void init(int n,int m){
        base.resize(n);
        fr(i,n)base[i].assign(m,0);
    }
    void build(){
        fr(i,base.size()){
            fr(j,base[i].size()){
                if(j)base[i][j]+=base[i][j-1];
                if(i)base[i][j]+=base[i-1][j];
                if(i&&j)base[i][j]-=base[i-1][j-1];
            }
        }
    }
    lli get(int xl,int xh,int yl,int yh){
        lli ans=base[xh][yh];
        if(xl)ans-=base[xl-1][yh];
        if(yl)ans-=base[xh][yl-1];
        if(xl&&yl)ans+=base[xl-1][yl-1];
        return ans%MOD;
    }
};
// O(M*N+Q) Q-No of Queries

struct partial1D{
    vi base;
    void init(int n){base.resize(n);}
    void build(){
        for(int i=1;i<base.size();i++)
            base[i]+=base[i-1];
    }
    void add(int l,int r,lli x){
        base[l]+=x;
        if(r+1<base.size())base[r+1]-=x;
    }
};
// O(N)
struct partial2D{
    vector<vi> base;
    void init(int n,int m){
        base.resize(n);
        fr(i,n)base[i].assign(m,0);
    }
    void build(){
        fr(i,base.size()){
            fr(j,base[i].size()){
                if(j)base[i][j]+=base[i][j-1];
                if(i)base[i][j]+=base[i-1][j];
                if(i&&j)base[i][j]-=base[i-1][j-1];
            }
        }
    }
    void add(int xl,int xh,int yl,int yh,lli x){
        xh++;yh++;
        base[xh][yh]+=x;
        base[xl][yh]-=x;
        base[xh][yl]-=x;
        base[xl][yl]+=x;
    }
};
// O(M*N+Q) Q-No of Queries

void solve(){
    prefix2D xx;
    lli n,m,q;
    cin>>n>>m>>q;
    xx.init(n,m);
    lli bb = 1;
    fr(i,n){
        fr(j,m)
        cin>>xx.base[i][j];
    }
    xx.build();
    fr(i,q){
        int xl,yl,xh,yh;
        cin>>xl>>yl>>xh>>yh;
        cout<<(xx.get(xl-1,xh-1,yl-1,yh-1)+MOD)%MOD<<endl;
    }
}
