class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        if(s1==s2) return true;
        
        vector<int> ind;
        int n = size(s1);
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) {ind.push_back(i);}
        }
        if(ind.size()==0) return true;
        if(ind.size() > 2) return false;
        if(ind.size()<=1) return false;
        swap(s1[ind[0]],s1[ind[1]]);
        return s1==s2;
    }
};