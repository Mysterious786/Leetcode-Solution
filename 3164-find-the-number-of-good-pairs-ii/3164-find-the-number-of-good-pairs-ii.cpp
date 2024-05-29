#define ll long long
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<ll, ll> mp;
        ll ans = 0;

        // Populate the map with counts of nums2 elements multiplied by k
        for (auto it : nums2) {
            mp[it * k]++;
        }

        // Iterate through nums1
        for (int i = 0; i < nums1.size(); i++) {
            // Skip if nums1[i] is not divisible by k
            if (nums1[i] % k != 0) continue;

            int num = nums1[i];

            // Check for all divisors of num
            for (int j = 1; j * j <= num; j++) {
                if (num % j != 0) continue;

                int f1 = j, f2 = num / j;
                
                // Add counts of divisors found in the map
                ans += mp[f1];
                if (f1 != f2) ans += mp[f2];
            }
        }

        return ans;
    }
};
