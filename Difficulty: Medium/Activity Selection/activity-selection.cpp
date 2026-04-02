class Solution {
  public:
    static bool comp(pair<int,int>a,pair<int,int>b)
    {
        return a.second<b.second;
    }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>>v;
        for(int i=0;i<start.size();i++)
        {
            v.push_back({start[i],finish[i]});
        }
        sort(v.begin(),v.end(),comp);
        int endTime=0;
        int cnt=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first>endTime)
            {
                endTime=v[i].second;
                cnt++;
            }
        }
        return cnt;
    }
};