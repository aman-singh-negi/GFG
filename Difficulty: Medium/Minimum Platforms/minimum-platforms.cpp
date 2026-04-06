class Solution {
  public:
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first<b.first)return true;
        else if(a.first==b.first && a.second>b.second)return true;
        return false;
    }
    int minPlatform(vector<int>& start, vector<int>& end) {
        // code here
        int maxi=0;
        int cnt=0;
        vector<pair<int,int>>data;
        for(int i=0;i<start.size();i++)
        {
            data.push_back({start[i],1});
        }
        for(int i=0;i<end.size();i++)
        {
            data.push_back({end[i],-1});
        }
        sort(data.begin(),data.end(),comp);
        for(int i=0;i<data.size();i++)
        {
            cnt+=data[i].second;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
