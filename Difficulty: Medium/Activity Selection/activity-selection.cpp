class Solution {
  public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[1]<b[1])return true;
        return false;
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n=start.size();
        vector<vector<int>>grid(n,vector<int>(2));
        for(int i=0;i<n;i++)
        {
            grid[i][0]=start[i];
            grid[i][1]=finish[i];
        }
        sort(grid.begin(),grid.end(),comp);
        int endtime=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(endtime<grid[i][0])
            {
                cnt++;
                endtime=grid[i][1];
            }
        }
        return cnt;
    }
};