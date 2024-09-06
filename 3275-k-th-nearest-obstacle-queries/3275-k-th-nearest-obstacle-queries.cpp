#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        multiset<int> ms;
        vector<int> ans;

        for (auto it : queries) {
            int x = abs(it[0]);
            int y = abs(it[1]);
            ms.insert(x + y);

            if (ms.size() < k) {
                ans.push_back(-1);
            } else {
                if (ms.size() > k) {
                    ms.erase(prev(ms.end()));
                }
                ans.push_back(*prev(ms.end()));
            }
        }
        return ans;
    }
};
