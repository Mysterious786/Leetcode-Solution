class Solution {
public:
    bool isSubstringPresent(string s) {
        string st = s;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size() - 1; i++){
            string str = s.substr(i, 2);
            if(st.find(str) != string::npos && s.find(str) != string::npos) return true;
        }
        return false;
    }
};