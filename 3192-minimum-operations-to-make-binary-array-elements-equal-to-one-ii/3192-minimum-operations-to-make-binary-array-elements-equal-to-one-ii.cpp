class Solution {
public:
    int minOperations(vector<int>& nums) {
    int res = 0, flip = 0;
    for (int n : nums)
        if (n + flip != 1) {
            ++res;
            flip = !flip;
        }
    return res;
}
};