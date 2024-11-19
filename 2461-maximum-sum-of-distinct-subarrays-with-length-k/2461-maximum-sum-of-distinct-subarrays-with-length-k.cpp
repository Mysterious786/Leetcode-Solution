class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long sum = 0;
        long long maxi = 0;
        int i=0;
        int j=0;
        int n = nums.size();
        while(j<n){
           mp[nums[j]]++;
           sum+=nums[j];
           if(j-i+1 ==k){
              if(mp.size() == k) maxi = max(sum,maxi);
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
               
                i++;  
           }
           j++;
        }
        return maxi;
    }
};