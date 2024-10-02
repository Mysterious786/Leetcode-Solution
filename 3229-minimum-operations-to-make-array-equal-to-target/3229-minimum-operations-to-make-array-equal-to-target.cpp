class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long pos = 0;
        long long neg = 0;
        long long count = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == target[i])
            {
                pos = 0,neg=0;
            }
            else if(nums[i] > target[i]) // minus op
            {
                if(pos) pos = 0;
                long long req = nums[i] - target[i];
                if(neg >= req) neg = req;
                else
                {
                    count+=(req-neg);
                    neg = req;
                }
                continue;
            }
            else{
                if(neg) neg = 0;
                long long req = target[i] - nums[i];
                if(pos >= req) pos = req;
                else
                {
                    count+=(req-pos);
                    pos = req;
                }
                continue;
            }
        }
        return count;
    }
};