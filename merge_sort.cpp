void merge(vector<lli>& arr, lli l, lli m, lli r)
{
    lli lsz=m-l+1;
    lli rsz=r-m;
    vector<lli> left(lsz);
    vector<lli> right(rsz);

    for(lli i=0;i<lsz;i++){
        left[i]=arr[l+i];
    }

    for(lli i=0;i<rsz;i++){
        right[i]=arr[m+1+i];
    }

    lli i=0,j=0,k=l;

    while(i<lsz && j<rsz){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    while(j < rsz)
    {
        arr[k]=right[j];
        k++;
        j++;
    }

    while(i<lsz)
    {
        arr[k]=left[i];
        k++;
        i++;
    }
}

void mergesort(vector<lli>& arr, lli l, lli r)
{
    if(l>=r){
        return;
    }
    lli mid=(l+r) / 2;
    mergesort(arr,l,mid);
    mergesort(arr, mid+1, r);
    merge(arr,l, mid,r);
}
