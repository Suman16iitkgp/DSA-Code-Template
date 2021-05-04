lli mod=1e9+7;
lli binary_exponentiation(lli a, lli b, lli mod) 
{
    lli ans =1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans = (ans*a) % mod;
        }
        a=(a*a) % mod;
        b/=2;
    }

    return ans;
}
// O(log b)
cout << binary_exponentiation(a,1e9+7-2,mod);
