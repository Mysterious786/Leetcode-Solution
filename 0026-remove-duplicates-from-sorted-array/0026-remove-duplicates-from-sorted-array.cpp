class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]]++;
                nums[count++] = nums[i]; // Place the unique element at the current count index
            }
        }
        return count; // Return the count of unique elements
    }
};
