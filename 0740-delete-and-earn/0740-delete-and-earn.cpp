class Solution {
    int helper(int ind,vector<int>& nums,map<int,int>& mp,int n,vector<int>& dp){
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int notTake = 0+helper(ind+1,nums,mp,n,dp);
        int take =0;
        take+=mp[nums[ind]]*nums[ind];
        if(ind+1<n && nums[ind]+1 == nums[ind+1]) take+=helper(ind+2,nums,mp,n,dp);
        else if(ind+1 < n && nums[ind]+1 != nums[ind+1]) take+=helper(ind+1,nums,mp,n,dp);
        return dp[ind] = max(take,notTake);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums) mp[it]++;
        vector<int> v;
        for(auto it : mp) v.push_back(it.first);
        sort(v.begin(),v.end());
        vector<int> dp(v.size()+1,-1);
        return helper(0,v,mp,v.size(),dp);
        
    }
};