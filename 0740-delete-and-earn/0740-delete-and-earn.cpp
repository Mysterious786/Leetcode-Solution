class Solution {

    private:
    int f(int ind,vector<pair<int,int>>& nums,vector<int>& dp)
    {
        if(ind < 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        if(ind == 0) return nums[ind].first*nums[ind].second;

        int notTake = 0 + f(ind-1,nums,dp);
        int take = 0;
        if(ind-1>=0 and nums[ind].first-nums[ind-1].first==1)
         take = nums[ind].first*nums[ind].second + f(ind-2,nums,dp);
         else take = nums[ind].first*nums[ind].second + f(ind-1,nums,dp);
        return dp[ind] = max(notTake,take);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int,int>> v;
        map<int,int> mp;
        for(auto it : nums) mp[it]++;
        for(auto it : mp) v.push_back({it.first,it.second});
    int n = v.size();
    vector<int> dp(n+1,-1);
        return f(n-1,v,dp);
    }
};