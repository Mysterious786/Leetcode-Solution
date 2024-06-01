class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xori = 0;
        int a = 0, b = 0;
        for (auto it : nums) xori ^= it;
        unsigned int val = xori & -(unsigned int)xori;  // Isolate the rightmost set bit using unsigned negation
        for (auto it : nums) {
            if (val & it) a ^= it;
            else b ^= it;
        }
        return {a, b};
    }
};
