class Solution {
    private:
    int check(int target,vector<int>& nums){
        int ans=0;
        for(auto it : nums){
            if(it>=target) ans++;
        }
        return ans;
    }
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int start = 1,end = 1001;
        int ans=-1;
        while(start<=end){
            int mid = (start+end)/2;
            int val = check(mid,nums);
            if(val==mid){
                ans = mid;
                break;
            }
            else if(val>mid ) start = mid+1;
            else end = mid-1;
            
        }
        return ans;
    }
};