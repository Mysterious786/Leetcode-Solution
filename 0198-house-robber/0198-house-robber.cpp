class Solution {
private:
    int dp[105];
    int robIt(int ind, vector<int>& nums, int n)
    {
        if(ind >= n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        // 2 cases broke current house and move to cur+2 house or not broke it
        int notTake = 0 + robIt(ind+1,nums,n);
        int take = nums[ind] + robIt(ind+2,nums,n);

        return dp[ind] = max(take,notTake);

    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return robIt(0,nums,n);
    }
};