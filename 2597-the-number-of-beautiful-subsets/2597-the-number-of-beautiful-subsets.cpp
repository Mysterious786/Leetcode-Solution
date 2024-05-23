class Solution {
    int v[1001];
    private:
    int f(int ind,vector<int>& nums,int k){
        if(ind == nums.size()) return 1;
        int take =0;
        if((nums[ind]-k) < 0 || v[nums[ind]-k]==0){
            v[nums[ind]]++;
           take =  f(ind+1,nums,k);
            v[nums[ind]]--;
        }
        int notTake = f(ind+1,nums,k);
        return take+notTake;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        memset(v,0,sizeof(v));
        return f(0,nums,k)-1;
        
    }
};