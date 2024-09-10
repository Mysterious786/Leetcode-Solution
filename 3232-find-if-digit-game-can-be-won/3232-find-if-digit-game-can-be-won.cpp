class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleDigit = 0;
        int doubleDigit = 0;
        for(auto it : nums)
        {
            if(it<=9) singleDigit+=it;
            else doubleDigit+=it;
        }
        if(singleDigit > doubleDigit || doubleDigit > singleDigit) return true;
        return false;
        
    }
};