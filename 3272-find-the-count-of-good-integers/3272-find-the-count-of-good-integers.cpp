#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<long long> nums;
    set<map<long long, long long>> st;

    long long factorial(long long num) {
        long long ans = 1;
        for (long long i = 2; i <= num; i++) ans *= i;
        return ans;
    }

    long long vectToNumber() {
        long long number = 0;
        for (auto it : nums) {
            number = (number * 10) + it;
        }
        return number;
    }

    void generatePermutation(long long left, long long right, long long k) {
        if (left > right) {
            long long generatedNumber = vectToNumber();
            if (generatedNumber % k == 0) {
                map<long long, long long> mp;
                for (long long digit : nums) {
                    mp[digit]++;
                }
                st.insert(mp);
            }
            return;
        }

        long long start = (left == 0) ? 1 : 0;
        for (long long i = start; i <= 9; i++) {
            nums[left] = nums[right] = i;
            generatePermutation(left + 1, right - 1, k);
        }
    }

    long long totalPermutation(map<long long, long long>& m) {
        long long count = 0;
        for (auto it : m) count += (it.second);
        long long ans = factorial(count);
        for (auto it : m) {
            ans /= factorial(it.second);
        }
        return ans;
    }

    long long zeroExcludedPermutation(map<long long, long long>& m) {
        if (m[0] == 0 || m.find(0) == m.end()) return 0;
        m[0]--;
        long long count = 0;
        for (auto it : m) count += (it.second);
        long long ans = factorial(count);
        for (auto it : m) {
            ans /= factorial(it.second);
        }
        m[0]++;
        return ans;
    }

public:
    long long countGoodIntegers(long long n, long long k) {
        nums.resize(n);
        generatePermutation(0, n - 1, k);
        long long ans = 0;
        for (auto it : st) {
            long long totPer = totalPermutation(it);
            long long zNo = zeroExcludedPermutation(it);
            ans += (totPer - zNo);
        }
        return ans;
    }
};
