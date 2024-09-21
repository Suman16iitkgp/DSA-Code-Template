
/*
Problem Statement
Taro and Jiro will play the following game against each other.
Initially, they are given a sequence a = (a1 , a2 , ... , aN ). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:
Remove the element at the beginning or the end of a. The player earns x points, where x is the removed element.
Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize X − Y , while Jiro tries to minimize X − Y .
Assuming that the two players play optimally, find the resulting value of X − Y . 
Constraints
All values in input are integers.
1≤N ≤3000 1≤ai ≤109
*/

#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;

lli n;
vector<lli> arr;
lli dp[3001][3001];
lli rec(lli left, lli right)
{
	if(left>right)
	{
		return 0;
	}

	if(left==right)
	{
		return arr[left];
	}

	if(dp[left][right]!=-1)
	{
		return dp[left][right];
	}

	lli temp= max(arr[left]-rec(left+1,right),arr[right]-rec(left,right-1));

	return dp[left][right]=temp;
	
}

void solve()
{
	cin >> n;
	// cout<<n;
	arr.resize(n+1);
	memset(dp,-1,sizeof(dp));
	for(lli i=1;i<=n;i++)
	{
		cin >> arr[i];
	}

	// lli res= 0;
	lli res=rec(1,n);

	cout<<res<<"\n";

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