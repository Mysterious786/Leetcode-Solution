class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v;
        int two(0),one(0),zero(0);
        for(auto it : nums){
            if(it == 2) two++;
            else if(it==1) one++;
            else zero++;
        }
        while(zero--) v.push_back(0);
        while(one--) v.push_back(1);
        while(two--) v.push_back(2);
        nums=v;
        
    }
};