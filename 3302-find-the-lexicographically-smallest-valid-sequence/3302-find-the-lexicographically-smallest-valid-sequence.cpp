class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int j = word2.size()-1;
        vector<int> lastOccur(j+1,-1);
        for(int i=n-1;(i>=0 && j>=0);i--)
        {
            if(j>=0 and word2[j] == word1[i])
            {
                lastOccur[j] = i;
                j--;
            }
        }
        vector<int> ans;
        j = 0;
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            if(j<word2.size())
            {
                if(word2[j] == word1[i] || (flag==true && (j==word2.size()-1 || (i+1<n and j+1<word2.size() and (i+1 <= lastOccur[j+1])) )))
                {
                    if(word2[j]!=word1[i]) flag = false;
                    ans.push_back(i);
                    j++;
                }
            }
        }
        if(j==word2.size()) return ans;
        return {};
    }
};