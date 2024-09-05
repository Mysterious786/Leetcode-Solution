class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxSum+=nums[i];
            maxi = max(maxSum,maxi);
            if(maxSum<0) maxSum=0;
            
        }
        return maxi;
    }
};