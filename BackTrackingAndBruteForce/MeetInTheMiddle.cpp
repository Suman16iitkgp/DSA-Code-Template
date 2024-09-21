#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
lli mod = 1e9 + 7;

/*
You have given an array of length N, and a number X. 
Find the number of subsets with the sum of elements less than equal to X.
*/

vector<lli> generate(vector<lli> arr)
{
	vector<lli> vc;
	lli n=lli(arr.size());

	for(lli mask=0;mask<(1<<n);mask++){
		lli sum=0;
		for(lli j=0;j<n;j++){
			if(mask & (1<<j)){
				sum+=arr[j];
			}
		}
		vc.push_back(sum);
	}

	sort(vc.begin(),vc.end());

	return vc;
}

lli find(vector<lli> arr,lli x)
{
	vector<lli> newarr[2];
	lli count=0;
	for(lli i=0;i<lli(arr.size());i++)
	{
		newarr[i&1].push_back(arr[i]);
	}

	vector<lli> sub1=generate(newarr[0]);
	vector<lli> sub2=generate(newarr[1]);
	for(lli i=0;i<lli(sub1.size());i++){
		count+=upper_bound(sub2.begin(),sub2.end(),x-sub1[i])-sub2.begin();
		// if(it!=sub2.end()){
		// 	// cout<<count<<" ";
		// 	count+= it-sub2.begin();
		// }
		
	}

	return count;
}

void solve()
{
	lli n,x;
	cin >> n >> x;
	vector<lli> vc(n);

	for(lli i=0;i<n;i++)
	{
		cin >> vc[i];
	}

	lli ans=find(vc,x);

	cout<<ans<<"\n";
}
signed main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cout<<"Hello";    
    
    lli t;
    cin >> t;

    while(t--)
    {
    	solve();
    }


}