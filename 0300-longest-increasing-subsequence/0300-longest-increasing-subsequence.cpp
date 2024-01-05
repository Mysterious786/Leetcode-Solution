#include <vector>
using namespace std;

class Solution {
private:
    int f(int ind, int prev, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind >= n) return 0;
        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int notTake = f(ind + 1, prev, n, nums, dp);
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) { 
            take = 1 + f(ind + 1, ind, n, nums, dp);
        }
        return dp[ind][prev + 1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size() + 1, vector<int>(10005, -1));
        return f(0, -1, nums.size(), nums, dp);
    }
};
