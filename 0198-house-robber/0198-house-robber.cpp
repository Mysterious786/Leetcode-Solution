class Solution {
    private:
    int f(int ind,vector<int>& nums,  vector<int>& dp){
        if(ind<0) return 0;
        if(ind ==0) return nums[0];
        if(dp[ind]!=-1) return dp[ind];


        int notTake = 0+f(ind-1,nums,dp);
        int take = nums[ind]+f(ind-2,nums,dp);
        return dp[ind]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(101,-1);
        if(n==2){
            return max(nums[0],nums[1]);
        }
        
        return f(n-1,nums,dp);
        
    }
};