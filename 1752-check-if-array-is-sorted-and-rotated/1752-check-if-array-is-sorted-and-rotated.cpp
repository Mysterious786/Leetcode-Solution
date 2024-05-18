class Solution {
public:
    bool check(vector<int>& v) {
        int count =0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i] > v[i+1]) {count++;}
        }
        if(count>1) return false;
        if(count ==0) return true;
        if(v[v.size()-1] <= v[0]) return true;
        return false;
    }
};