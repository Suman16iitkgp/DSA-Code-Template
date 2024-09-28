#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ld long double
#define rep(i,n) for(lli i=0;i<n;i++)
#define ii pair<lli,lli>
#define F first
#define S second
#define pb push_back
#define pob pop_back

/*
For each prefix of a given string S with N characters consisting of lowercase characters, 
we want to know whether the prefix is a periodic string. That is, for each i (2 <= i <= N) we want to know the largest K > 1 
(if there is one) such that the prefix of S with length i can be written as AK , that is A concatenated K times, for some string A. 
Of course, we also want to know the period K. If there are multiple AK print the maximum value of K.
*/

void solve()
{
    lli n;
    string s;

    cin>>n;
    cin>>s;
    // cout<<s;
    int kmp[n+1];
    for(lli i=1;i<=n;i++){
        kmp[i]=0;
    }
    int i=1,j=0;
    kmp[0]=-1;

    while(i<n)
    {

        while(j!=-1 && s[i]!=s[j] )j=kmp[j];
        i++;j++;
        kmp[i]=j;
    }


    // cout<<i;

    for(lli i=2;i<=n;i++)
    {
        // cout<<kmp[i]<<" ";
        if(i%(i-kmp[i]) == 0 && kmp[i]!=0){
            cout<<i<<" "<<i/(i-kmp[i])<<endl;
        }
    }

    cout<<endl;

}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    lli _t;
    cin >> _t;
    // _t=1;
    for(lli i=1;i<=_t;i++){
        // lli res=solve();;
        cout<<"Test case #"<<i<<endl;
        solve();
    }


    // while(_t--)
    // {
    //     solve();
    // }
    return 0;
 
}