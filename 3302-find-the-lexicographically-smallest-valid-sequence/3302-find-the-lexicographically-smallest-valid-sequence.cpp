class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<int> last(size2,-1);
        vector<int> ans;
        bool flag = true;
        int j = size2-1;
        for(int i=size1-1;(i>=0 and j>=0);i--)
        {
            if(j>=0 and word1[i] == word2[j])
            {
                last[j] = i;
                j--;
            }
        }
        
        j = 0;
        for(int i=0;i<size1;i++)
        {
            if(j<size2)
            {
                if(word1[i] == word2[j] || (flag and (j==size2-1 || (i+1<size1 and j+1<size2 and (i+1<=last[j+1])))))
                {
                    if(word1[i]!=word2[j]) flag = false;
                    ans.push_back(i);
                    j++;
                }
            }
        }
        if(j==size2) return ans;
        return {};
    }
};