#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort by width and then by height in descending order if widths are the same
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        // Debug output to verify sorting
       // for(const auto& it : envelopes) {
        //    cout << it[0] << " " << it[1] << endl;
        //}
        
        // Extract the heights and perform LIS
        vector<int> heights;
        for (const auto& envelope : envelopes) {
            heights.push_back(envelope[1]);
        }
        
        return lengthOfLIS(heights);
    }
    
private:
    int lengthOfLIS(const vector<int>& nums) {
        vector<int> lis;
        for (int num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }
        return lis.size();
    }
};


