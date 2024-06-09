class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        int curr = 0;
        int ans =0;
        for(auto it : nums){
            curr = (curr + it%k+k)%k;
            ans = ans+mp[curr];
            mp[curr]++;
        }
        return ans;
        
    }
};