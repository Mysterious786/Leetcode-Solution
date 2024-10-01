class Solution {
    private:
    vector<int> z_function(const string &s) {
    vector<int> z(s.size());
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
  }
  return z;
    }
    
public:
    int minStartingIndex(string s, string pattern) {
        int size1 = size(s);
        int size2 = size(pattern);
        string s1 = pattern+s;
        reverse(pattern.begin(),pattern.end());
        reverse(s.begin(),s.end());
        string s2  = pattern+s;
        vector<int> pref = z_function(s2);
        vector<int> suff = z_function(s1);
        for(int i=0;i<=size1-size2;i++)
        {
            if(suff[i+size2]+pref[size1-i]>=size2-1) return i;
        }
        return -1;
    }
};