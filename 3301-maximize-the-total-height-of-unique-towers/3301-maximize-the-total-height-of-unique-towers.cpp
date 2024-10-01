#define ll long long

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        map<ll,ll> mp;
        int n = maximumHeight.size();
        sort(maximumHeight.begin(),maximumHeight.end());
        mp[maximumHeight[n-1]]++;
        for(int i=n-2;i>=0;i--)
        {
            if(mp.find(maximumHeight[i])!=mp.end())
            {
                maximumHeight[i] = maximumHeight[i+1] - 1;
            }
            if(maximumHeight[i]<=0) return -1;
            mp[maximumHeight[i]]++;
        }
        for(int i=0;i<n-1;i++)
        {
            if(maximumHeight[i]==maximumHeight[i+1]) return -1;
        }
        return accumulate(maximumHeight.begin(),maximumHeight.end(),0ll);
    }
};