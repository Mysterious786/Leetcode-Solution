class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len1 = beginWord.size();
        int len2 = endWord.size();
        if(len1 != len2) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        map<string,int> mp,mp2;
        for(auto it : wordList) mp[it]++;
        while(!q.empty()){
            auto s = q.front();
            q.pop();
            string queueString = s.first;
            int steps = s.second;
            int sz = queueString.size();
            if(queueString==endWord) return steps;
            for(int i=0;i<sz;i++){
                char c = queueString[i];
                for(char ch ='a';ch<='z';ch++){
                    if(c!=ch){
                        queueString[i] = ch;
                        if(mp.find(queueString)!=mp.end() and mp2.find(queueString)==mp2.end()){
                            q.push({queueString,steps+1});
                            mp2[queueString]++;
                        }
                    }
                }
                queueString[i] = c;
            }
        }

        return 0;
    }
};