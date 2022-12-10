#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define rep(i,n) for(lli i=0;i<n;i++)
#define ii pair<lli,lli>
#define F first
#define S second

struct Unionfind
{
    lli n, sz, *rk, *pt;  // sz=set_size, rk=rank, pt=parent
    Unionfind(){}
    Unionfind(lli a){
        n=sz=a;
        rk = new lli[n+1];
        pt = new lli[n+1];
        for(lli i=1;i<=n;i++)
        {
            pt[i]=i,rk[i]=1;
        }
    }
    lli find(lli x)
    {
        if(pt[x]==x){return x;}

        return pt[x]=find(pt[x]);
    }
    void merge(lli x, lli y)
    {
        lli xrt=find(x), yrt=find(y);  // xrt=xroot, yrt=yroot
        if(xrt==yrt) return;
        if(rk[xrt]>=rk[yrt]){
            rk[xrt]+=rk[yrt];
            pt[yrt]=xrt;
        }else{
            rk[yrt]+=rk[xrt];
            pt[xrt]=yrt;
        }
        sz-=1;
    }
    void reset()
    {
        sz=n;
        for(lli i=1;i<=n;i++){pt[i]=i,rk[i]=1;}
    }

    lli size(){ return sz;}
    void print(){for(lli i=1;i<=n;i++)cout<<i<<"->"<<pt[i]<<"\n";}

};
