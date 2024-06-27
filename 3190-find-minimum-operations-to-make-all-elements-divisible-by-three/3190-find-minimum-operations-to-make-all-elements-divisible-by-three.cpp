class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans =0;
        for(auto it : nums){
            if(it%3==0) continue;
            else if(it%3==1) ans+=1;
            else if(it%3==2) ans+=1;
        }
        return ans;
    }
};