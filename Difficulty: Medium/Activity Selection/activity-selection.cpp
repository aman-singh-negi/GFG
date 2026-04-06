class Solution {
  public:   
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second<b.second)return true;
        return false;
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int cnt=0;
        int endTime=INT_MIN;
        vector<pair<int,int>>v;
        for(int i=0;i<start.size();i++)
        {
            v.push_back({start[i],finish[i]});
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++)
        {
            int st=v[i].first;
            int et=v[i].second;
            if(endTime<st)
            {
                cnt++;
                endTime=et;
            }
            else
            {
                continue;
            }
        }
        return cnt;
    }
};