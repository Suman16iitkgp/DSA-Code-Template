/*
Problem Statement
There is a set A = {a1 , a2 , ... , aN } consisting of N positive integers. Taro and Jiro will play the following game against each other.
Initially, we have a pile consisting of K stones. The two players perform the following operation alternately, starting from Taro:
Choose an element x in A, and remove exactly x stones from the pile.
A player loses when he becomes unable to play. Assuming that both players play optimally, determine the winner.
Constraints
All values in input are integers. 1≤N ≤100
1 ≤ K ≤ 105
1≤a1 <a2 <...<aN ≤K
*/

#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;

lli n,k;
vector<lli> arr;
lli dp[100010];
lli rec(lli x)
{
	// if(z==0) return dp[stone]=1;
	if(x<=0)
	{
		return 0;
	}

	if(dp[x]!=-1)
	{
		return dp[x];
	}
	
	lli ans=1;
	
	lli flag=0;
	for(lli i=0;i<n; i++)
	{
		if((x-arr[i]) >= 0){
			ans=min(ans, rec(x-arr[i]));
			flag++;
		}
		
	}
	if(ans==1)
	{
		return dp[x]=0;
	}else{
		return dp[x]=1;
	}
	

	// return temp;
}

void solve()
{
	cin >> n >> k;
	// cout<<k;
	arr.resize(n);
	memset(dp,-1,sizeof(dp));
	for(lli i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	// lli res= 0;
	lli res=rec(k);

	if(res==1)
	{
		cout<<"First\n";
	}else if(res==0){
		cout<<"Second\n";	
	}

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