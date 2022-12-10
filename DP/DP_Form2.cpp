#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;
int N=1e6;

lli n,k;
vector<lli> arr;
lli dp[1000000];

lli rec(lli level)
{

	if(level==n)
	{
		return 0;
	}

	if(dp[level]!=-1){
		return dp[level];
	}

	lli ans1=rec(level+1)+abs(arr[level+1]-arr[level]);
	dp[level]=ans1;

	for(lli i=2;i<=k;i++)
	{
		if(level+i<=n)
		{
			lli ans2=min(ans1,rec(level+i)+abs(arr[level+i]-arr[level]));
			ans1=ans2;
			dp[level]=ans1;	
		}
	}
	// cout<<ans<<"\n";
	return ans1;
}

void solve()
{
	
	cin >> n >> k;

	memset(dp,-1,sizeof(dp));
	arr.resize(n+1);
	for(lli i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	lli ans=rec(1);
	cout<<ans<<"\n";
}

signed main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	// lli t;
	// cin >> t;
	// while(t--)
	// {
	// 	solve();
	// }

	solve();

    
    return 0;


}