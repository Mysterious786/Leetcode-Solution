class Solution {
private:
    int lengthOfLCS(int ind1, int ind2, int n, int m, string& text1, string& text2,vector<vector<int>>& dp)
    {
        if(ind1 == n || ind2 == m) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2])
        {
            return dp[ind1][ind2] = 1 + lengthOfLCS(ind1+1,ind2+1,n,m,text1,text2,dp);
        }
        else
        {
            return dp[ind1][ind2] = max(lengthOfLCS(ind1+1,ind2,n,m,text1,text2,dp),lengthOfLCS(ind1, ind2+1,n,m,text1,text2,dp));
        }
        return 0;

    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return lengthOfLCS(0,0,n,m,text1,text2,dp);
    }
};