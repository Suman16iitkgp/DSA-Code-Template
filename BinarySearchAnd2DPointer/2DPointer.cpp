#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
using ld=long double;
#define rep(i,a,b) for(lli i=a;i<=b;i++)
lli mod = 1000000007;
const int N = 1e9 + 7;
lli n,k;
vector<lli> arr1;

/*
Given an array of N integers A. The score of a subarray is the sum of all integers in the subarray. 
Mr.X calculated the score of all N*(N+1))/2 subarray. Mr.X wants you to find the median of the array containing 
the score of all the subarray.
Output the median of the array containing the score of all the subarray in a new line.
*/


lli n;
vector<lli> A;

bool check( lli val ){
    lli medianCnt = n * (n+1) / 2;
    if( medianCnt%2 == 0 ){
        medianCnt = medianCnt/2;
    }else{
        medianCnt = (medianCnt+1)/2;
    }

    lli head = -1, tail = 0, curSum = 0, totCnt=0;

    while( tail < n ){
        while( head+1 < n && curSum + A[head+1] <= val ){
            head++;
            curSum += A[head];
        }

        totCnt += head-tail+1;

        if( head >= tail ){
            curSum -= A[tail];
            tail++;
        }else{
            tail++;
            head = tail-1;
        }
        
    }

    return totCnt >= medianCnt;

}
void solve() {
    cin >> n;

    lli low = 0, high = 0 , ans = -1;
    A.resize( n );
    for( lli i=0; i<n; i++ ){
        cin >> A[i];
        high += A[i];
    }

    // sort( A.begin(), A.end() );

    while( low <= high ){
        lli mid = (low+high)/2;

        if( check(mid) ){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    cout << ans << "\n";

}