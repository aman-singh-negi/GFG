/* The functions which
builds the segment tree */
void f(int idx,int low,int high,int arr[],int seg[])
{
    if(low==high)
    {
        seg[idx]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    f(2*idx+1,low,mid,arr,seg);
    f(2*idx+2,mid+1,high,arr,seg);
    int left=seg[2*idx+1];
    int right=seg[2*idx+2];
    seg[idx]=min(left,right);
}
int *constructST(int arr[], int n) {
    // Your code here
    int* seg = new int[4*n];
    f(0, 0, n-1, arr, seg);
    return seg;
}

/* The functions returns the
 min element in the range
 from a and b */
int solve(int st[],int idx,int low,int high,int a,int b)
{
    //Complete
    if(low>=a && high<=b)
    {
        return st[idx];
    }
    //do not overlap
    else if(low>b || high<a)
    {
        return INT_MAX;
    }
    else
    {
        //partial
        int mid=(low+high)/2;
        int left=solve(st,idx*2+1,low,mid,a,b);
        int right=solve(st,idx*2+2,mid+1,high,a,b);
        return min(left,right);
    }
}
int RMQ(int st[], int n, int a, int b) {
    
    // Your code here
    return solve(st,0,0,n-1,a,b);
}