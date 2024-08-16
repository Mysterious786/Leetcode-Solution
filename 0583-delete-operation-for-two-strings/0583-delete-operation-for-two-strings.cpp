#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // if my string equal I will move
        // else either I can delete the the character of s1 or s2 and min of these things
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]) dp[i][j] = 1+dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
       return (n-dp[0][0])+(m-dp[0][0]);
    }
};