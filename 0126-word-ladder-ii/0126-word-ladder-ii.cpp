class Solution {
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;

private:
    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int len1 = beginWord.size();
        int len2 = endWord.size();
        if (len1 != len2) return {};

        unordered_set<string> st(wordList.begin(), wordList.end());
        // Check if the end word is present in the wordList
        if (st.find(endWord) == st.end()) return {};

        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if (word == endWord) break;

            for (int i = 0; i < len1; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        mp[word] = steps + 1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        b = beginWord; // Start DFS from endWord and look for paths to beginWord
        if (mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};
