/*
You've given an array A of N integers. Your task is to support the following queries.
    0 x y : Modify the number at index x to y.
    1 l r : Print the count the number of even numbers in range l to r inclusive.
    2 l r : Print the count the number of odd numbers in range l to r inclusive.
*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double


// Node definition
struct node{
    lli n_ev;
    lli n_od;
    node(lli ev=0, lli od=0)
    {
        n_ev=ev;
        n_od=od;
    }
};

lli n,q;
lli arr[100100];
node tr[400200];

// merge logic
node merge(node a, node b)
{
    return node(a.n_ev + b.n_ev,a.n_od + b.n_od);
}

// build Segment Tree
void build(lli id, lli l, lli r)
{
    if(l==r)
    {
        if(arr[l]%2==1){
            tr[id]=node(0,1);
        }else if(arr[l]%2==0){
            tr[id]=node(1,0);
        }
        return;   
    }
    lli mid=(l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    tr[id]=merge(tr[id<<1],tr[id<<1|1]);
}

//update Segment Tree
void update(lli id,lli l, lli r, lli pos, lli val)
{
    if(pos<l || pos>r){
        return;
    }

    if(l==r && l==pos)
    {
        if(val%2==1 && arr[pos]%2==0){
            tr[id].n_ev-=1;
            tr[id].n_od+=1;
        }else if(val%2==0 && arr[pos]%2==1){
            tr[id].n_ev+=1;
            tr[id].n_od-=1;
        }
        arr[pos]=val;
        return;
    }
    lli mid=(l+r)/2;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    tr[id]=merge(tr[id<<1],tr[id<<1|1]);
}

//query Segment Tree
lli query(lli id, lli l, lli r, lli lq, lli rq)
{
    if(l>rq || r<lq)
    {
        return 0;
    }

    if(lq<=l && rq>=r){
        return tr[id].n_ev;
    }
    lli mid=(l+r)/2;
    node qtemp=merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
    return qtemp.n_ev;

}

void solve()
{
    cin >> n;
    for(lli i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    build(1,0,n-1);
    cin >> q;
    while(q--)
    {
        lli tm1,tm2,tm3;
        cin >> tm1 >> tm2 >> tm3;
        if(tm1==0)
        { 
            tm2--;
            update(1,0,n-1,tm2,tm3);
        }else if(tm1==1)
        {
            tm2--;
            tm3--;
            lli ans=query(1,0,n-1,tm2,tm3);
            cout << ans <<"\n";
        }else if(tm1==2)
        {
            tm2--;
            tm3--;
            lli ans2=query(1,0,n-1,tm2,tm3);
            ans2=tm3-tm2+1-ans2;
            cout << ans2 <<"\n";
        }
    }
    

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    lli _t;
    // cin >> _t;
    _t=1;

    // node b=node(0,1);
    // cout << b.n_od <<"\n";
    while(_t--){solve();}
    return 0;

}