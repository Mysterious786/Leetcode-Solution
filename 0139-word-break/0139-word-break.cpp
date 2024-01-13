
class Solution {
set<string> st;
map<string,bool> dp;
    private:
    bool f(string s){
        if(s.size() == 0) return true;
        if(dp.find(s)!=dp.end()) return dp[s];

        for(int i=0;i<s.size();i++){
            string next = s.substr(0,i+1);
            if(st.count(next)){
                if(f(s.substr(i+1))){
                    return dp[s] = true;
                }
            }
        }
        return dp[s] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it : wordDict) st.insert(it);
        return f(s);
        
    }
};