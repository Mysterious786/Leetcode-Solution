#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        std::vector<int> series;
        std::vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int pos = findInsertPosition(series, nums[i]);
            series.insert(series.begin() + pos, nums[i]);
            ans[i] = pos;
        }
        return ans;
    }

private:
    int findInsertPosition(const std::vector<int>& series, int target) {
        int l = 0;
        int h = series.size();
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (series[mid] >= target) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
