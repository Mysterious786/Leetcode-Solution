class Solution {
private:
    long long find(int ind, bool flag, vector<int>& nums, vector<vector<long long>>& dp) {
        if (ind >= nums.size()) {
            return 0;
        }
        if (dp[ind][flag] != -1) {
            return dp[ind][flag];
        }

        long long take = LLONG_MIN;
        long long nTake = LLONG_MIN;

        if (flag == 1) {
            nTake = (-nums[ind]) + find(ind + 1, 0, nums, dp);
        }
        take = nums[ind] + find(ind + 1, 1, nums, dp);
        
        return dp[ind][flag] = max(take, nTake);
    }

public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
        return nums[0] + find(1, true, nums, dp);
    }
};
