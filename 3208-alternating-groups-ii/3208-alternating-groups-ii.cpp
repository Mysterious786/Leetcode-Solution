class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> temp = colors;
        for(int i=0;i<k;i++) temp.push_back(colors[i]);
        int prev =colors[0];
        int count = 1;
        int ans =0;
        for(int i=1;i<temp.size()-1;i++){
            if(prev!=temp[i]){
                count++;
                prev=temp[i];
            }
            else{
                count = 1;
                prev = temp[i];
            }
            if(count>=k) ans++;
            
            
            
        }
        return ans;
    }
};