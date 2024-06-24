class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size() - 1;
        double ans = INT_MAX;
        while (s < e) {
            double val = (double)(nums[s] + nums[e]) / 2.0;
            ans = min(ans, val);
            s++;
            e--;
        }
        return ans;
    }
};
