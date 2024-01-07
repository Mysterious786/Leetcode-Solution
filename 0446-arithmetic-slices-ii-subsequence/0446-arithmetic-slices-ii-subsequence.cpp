class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();int result = 0;
        std::vector<std::unordered_map<long long, int>> mp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];
                int count_at_j = mp[j][diff];

                result += count_at_j;

                // Increment the count at index i
                mp[i][diff] += count_at_j + 1;
            }
        }

        return result;
    }
};

