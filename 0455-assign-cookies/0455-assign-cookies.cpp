class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int size1 = g.size();
        int count =0;
        int size2 = s.size();
        while(i<size1 && j<size2){
            if(g[i]<=s[j]){
                i++;
                j++;
                count++;
                
            }
            else j++;
        }
        return count;
        
    }
};