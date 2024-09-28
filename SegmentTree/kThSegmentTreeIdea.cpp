#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double

/*
There are N persons standing in the queue. They are numbered from 1 to N. Hi is the height of the person i. 
Pi is the number of persons who are taller than i and standing in front of i. 
Given these two arrays H and P, your task is to find the actual order of the queue. 
It is guaranteed that the height of each person will be unique.
*/

lli n;
lli arr[100100];
lli tr[400400];

void build(lli id, lli l, lli r)
{
    if(l==r){
        tr[id]=1;
        return;
    }
    lli mid=(l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    tr[id]=tr[id<<1]+tr[id<<1|1];
}

void update(lli id, lli l,lli r,lli idx,lli cnt)
{
    if(idx<l || idx>r){
        return;
    }
    if(l==r){
        tr[id]=cnt;
        return;
    }
    
    lli mid=(l+r)/2;
    update(id<<1,l,mid,idx,cnt);
    update(id<<1|1,mid+1,r,idx,cnt);
    tr[id]=tr[id<<1]+tr[id<<1|1];

}

lli query(lli id, lli l, lli r,lli val)
{
    if(l==r){
        return l;
    }
    lli mid=(l+r)/2;
    if(tr[2 * id] >= val) return query(id<<1, l, mid, val);
    return query(id<<1|1, mid + 1, r, val - tr[id<<1]);
}

void solve()
{
    cin >> n;
    pair<lli,lli> p[n];

    for(lli i=0;i<n;i++)
    {
        cin >> p[i].first;
        p[i].second=i;
    }

    lli P[n];
    for(lli i=0;i<n;i++)
    {
        cin >> P[i];
    }

    sort(p, p+n);

    build(1,0,n-1);

    lli ans[n];

    for(lli i=0;i<n;i++)
    {
        lli h=p[i].first;
        lli j=p[i].second;

        lli pos=query(1,0,n-1, P[j]+1);

        ans[pos]=j;

        update(1,0,n-1,pos,0);
    }

    for(lli i=0;i<n;i++)
    {
        cout<<ans[i]+1<<" ";
    }

    cout<<"\n";

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
    while(_t--){
        solve();
    }
    return 0;

}