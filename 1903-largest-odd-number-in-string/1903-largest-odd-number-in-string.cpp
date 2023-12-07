class Solution {
public:
    string largestOddNumber(string num) {
        int pos = -1;
        for(int i=num.size()-1;i>=0;i--){
            int val = (num[i]-'0');
            if(val%2){
                pos = i;
                break;
            }
        }
        string ans ="";
        for(int i=0;i<=pos;i++){
            ans+=(num[i]);
        }
        return ans;
        
    }
};