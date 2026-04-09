class Solution {
  public:
    int f(int mid,vector<int>&stalls,int k)
    {
        int cnt=1;
        int back=stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            int diff=stalls[i]-back;
            if(diff>=mid)
            {
                back=stalls[i];
                cnt++;
            }
        }
        return cnt>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        int low=1;
        int ans=-1;
        sort(stalls.begin(),stalls.end());
        int high=stalls[n-1]-stalls[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(f(mid,stalls,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};