class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //sol1:
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
        
    }
};