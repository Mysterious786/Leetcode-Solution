#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Fill the dp table for LCS length
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        // Build the shortest common supersequence using the dp table
        int i = 0, j = 0;
        string ans;
        while(i < n && j < m) {
            if(str1[i] == str2[j]) {
                ans.push_back(str1[i]);
                i++;
                j++;
            } else if(dp[i + 1][j] >= dp[i][j + 1]) {
                ans.push_back(str1[i]);
                i++;
            } else {
                ans.push_back(str2[j]);
                j++;
            }
        }

        // Append the remaining characters of str1 and str2
        while(i < n) {
            ans.push_back(str1[i]);
            i++;
        }
        while(j < m) {
            ans.push_back(str2[j]);
            j++;
        }

        return ans;
    }
};
