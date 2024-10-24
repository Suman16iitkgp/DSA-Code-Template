/*
You are given two integers N and S. Find the number of positive integers X less than equal to N, 
such that the difference between X and the sum of its digits (in decimal representation) is not less than S.
*/


bool check(int mid, int s){
    int digSum = 0;
    int temp = mid;
    while(temp > 0){
        digSum += temp%10;
        temp = temp/10;
    }

    int diff = mid - digSum;

    return diff >= s;
}

void solve(){
   int n, s;
   cin >> n >> s;

   int low = 1, high = n, ans = -1;

   while ( low <= high )
   {
        int mid = (low+high)/2;
        if( check(mid, s) ){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
   }

    if( ans == -1 ){
        cout << 0 << "\n";
        return;
    }
   int res = n-ans+1;

   cout << res << "\n";
   
}
