class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int count = 0;
        int ans = 1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxi) count++;
            else{
                
               
                count = 0;
            }
             ans = max(ans,count);
        }
        return ans;
    }
};