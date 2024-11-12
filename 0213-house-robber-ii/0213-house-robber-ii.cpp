class Solution {
    private:
    int f(int ind,vector<int>& num,  vector<int>& dp){
        if(ind<0) return 0;
        if(ind ==0) return num[0];
        if(dp[ind]!=-1) return dp[ind];


        int notTake = 0+f(ind-1,num,dp);
        int take = num[ind]+f(ind-2,num,dp);
        return dp[ind]=max(take,notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        if(n==1) return nums[0];
         vector<int> temp1(begin(nums), end(nums)-1);
        vector<int> temp2(begin(nums)+1, end(nums));
        int size = temp1.size();
        int first = f(size-1,temp1,dp);
        dp.clear();
        dp.assign(n, -1);
        int second = f(size-1,temp2,dp);
        return max(first,second);
       
        
    }
};