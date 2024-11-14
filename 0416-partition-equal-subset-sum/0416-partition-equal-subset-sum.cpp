class Solution {
    int dp[202][10001]; // Adjusted dp array size for memory efficiency
    
    bool checkPartition(int ind, int n, vector<int>& arr, int target) {
        if (target == 0) return true;
        if (ind == n - 1) return target == arr[ind];
        
        if (dp[ind][target] != -1) return dp[ind][target];
        
        bool notTake = checkPartition(ind + 1, n, arr, target);
        bool take = false;
        
        if (target >= arr[ind]) {
            take = checkPartition(ind + 1, n, arr, target - arr[ind]);
        }
        
        return dp[ind][target] = notTake || take;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum % 2 == 1) return false;
        
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return checkPartition(0, n, nums, totalSum / 2);
    }
};
