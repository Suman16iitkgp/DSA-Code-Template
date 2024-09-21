/*
You are given strings and . Find one longest string that is a subsequence of both and .
Notes
A subsequence of a string is the string obtained by removing zero or more characters from and
concatenating the remaining characters without changing the order.
Constraints
strings consisting of lowercase English letters.
1 ≤ ∣s∣, ∣t∣ ≤ 3000

*/

#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;

string s1,s2,sol;

lli dp[3001][3001];
lli back[3001][3001];
lli rec(lli i, lli j)
{

	if(i>=s1.length() || j>=s2.length())
	{
		return 0;
	}

	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}

	lli ans=max(rec(i+1,j),rec(i,j+1));

	if(s1[i] == s2[j])
	{
		ans=max(ans, 1+rec(i+1,j+1));

	}
	dp[i][j]=ans;


	if(ans == (1+rec(i+1,j+1)) && s1[i]==s2[j]){
		back[i][j]=1;
	}else if(ans == rec(i+1,j)){
		back[i][j]=2;
	}else{
		back[i][j]=3;
	}
	return ans;
	
	
}

void gensol(lli i, lli j)
{
	if(i==s1.length() || j==s2.length() || back[i][j]==-1)
	{
		return;
	}else if(back[i][j]==1){
		sol+=s1[i];
		gensol(i+1,j+1);
	}else if(back[i][j]==2){
		gensol(i+1,j);
	}else{
		gensol(i,j+1);
	}
	// else{
	// 	gensol(i,j+1);
	// }
}
void solve()
{
	cin >> s1 >> s2;
	// cout<<s1<<endl;
	// cout<< s2 << endl;
	memset(dp,-1,sizeof(dp));
	memset(back,-1,sizeof(back));
	lli temp=rec(0,0);
	// sol="";
	gensol(0,0);

	cout<<sol;
	
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