class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int len = words[i].size();
            int j = i + 1;
            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }
            int spaces = maxWidth - len;
            int gaps = j - i - 1;
            string line = words[i];
            for (int k = i + 1; k < j; k++) {
                if (j == n) line += " ";
                else line += string(spaces / gaps + (k - i <= spaces % gaps), ' ');
                line += words[k];
            }
            line += string(maxWidth - line.size(), ' ');
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};
