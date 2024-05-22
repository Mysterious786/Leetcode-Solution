class Solution {
private:
    bool isPalin(int i, int j, string s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void f(int i, string s, int n,  vector<string> v, vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(v);
            return ;
        }
   
    
        for (int j = i; j < n; j++) {
            if (isPalin(i, j, s)) {
           
                string sub = s.substr(i, j - i + 1);
               ;
                v.push_back(sub);
                f(j + 1, s, n, v, ans);
                v.pop_back();
               
              
                
            }
        }

    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        f(0, s, s.size(), v, ans);
        return ans;
    }
};