class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 1;
        for(int end =1;end<nums.size();end++){
            if(start==1 or nums[end] != nums[start-2]){
                nums[start++] = nums[end];
            }
        }
        return start;
        
    }
};