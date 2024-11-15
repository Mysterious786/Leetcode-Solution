class Solution {
    int dp[1004][1004];
        int lengthOfLCS(int ind1, int ind2, int n, int m, string& text1, string& text2)
    {
        if(ind1 == n || ind2 == m) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2])
        {
            return dp[ind1][ind2] = 1 + lengthOfLCS(ind1+1,ind2+1,n,m,text1,text2);
        }
        else
        {
            return dp[ind1][ind2] = max(lengthOfLCS(ind1+1,ind2,n,m,text1,text2),lengthOfLCS(ind1, ind2+1,n,m,text1,text2));
        }
        return 0;

    }
public:
    int longestPalindromeSubseq(string s) {
        string text2 = s;
        memset(dp,-1,sizeof(dp));
        reverse(text2.begin(),text2.end());
        int n = s.size();
        return n - lengthOfLCS(0,0,n,n,s,text2);

    }   int minInsertions(string s) {
        return longestPalindromeSubseq(s);
    }
};