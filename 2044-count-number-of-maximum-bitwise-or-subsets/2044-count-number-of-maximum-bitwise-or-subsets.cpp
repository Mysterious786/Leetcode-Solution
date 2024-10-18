class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = size(nums);
        int ans = 0;
        int maxi = 0;
        int count = 0;
        for(int i=0;i<(1<<n);i++)
        {
            int sum = 0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    sum|=nums[j];
                }
            }
            if(sum == maxi)
            {
                count++;
            }
            else if(sum > maxi)
            {
                count = 1;
                maxi = sum;
                ans = maxi;
            }
            else continue;
        }
        return count;
    }
};