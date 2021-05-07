lli l,r;
vector<lli> mark1,mark2;
vector<lli> prime;

void sieve()
{
    lli sz= int(sqrt(r))*1ll;
    mark1.resize(sz+1);

    for(lli i=2;i<=sz;i++){
        mark1[i]=1;
    }
    mark1[0]=0;
    mark1[1]=0;
    for(lli i=2;i<=sz;i++){
        if(mark1[i]){
            prime.push_back(i);
           for(lli j=i*i;j<=sz;j+=i){
                mark1[j]=0;
           }
        }
        
    }
}
// O(nloglogn)

void segment_sieve()
{
    mark2.resize(r-l+1);
    for(lli i=0;i<=r-l;i++){
        mark2[i]=1;
    }

    if(l==1){
        mark2[0]=0;
    }
    
    for(lli pm:prime){
        lli temp =((l+pm-1)/pm)*pm;
        for(lli j=temp;j<=r;j+=pm){
            if(j!=pm){
                mark2[j-l]=0;
            } 
        }
    }

}
// O((r-l+1)*loglog(r-l+1)
