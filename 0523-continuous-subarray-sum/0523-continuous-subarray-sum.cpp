class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> modMap; // To store (mod value, first occurrence index)
        modMap[0] = -1; // To handle the case where the subarray starts from index 0
        int sum = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = sum % k;
            
            
            if (modMap.find(mod) != modMap.end()) {
                if (i - modMap[mod] > 1) {
                    return true; // Found a subarray with at least 2 elements
                }
            } else {
                modMap[mod] = i; // Store the first occurrence of this mod value
            }
        }
        
        return false;
    }
};

