class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        int ele =0;
        for(int i=0;i<n;i++){
            if(count ==0){
                count++;
                ele=nums[i];
            }
            else if(nums[i]==ele) count++;
            else count--;
        }
        return ele;
        
    }
};