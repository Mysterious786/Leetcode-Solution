class Solution {
public:
    void sortColors(vector<int>& nums) {
     int one=0,two=0,zero=0;
        for(auto it : nums){
            if(it==1) one++;
            else if(it==2) two++;
            else zero++;
        }
        int count =0;
        while(zero--) nums[count++] =0;
        while(one--) nums[count++] = 1;
        while(two--) nums[count++] =2;
        
        
    }
};