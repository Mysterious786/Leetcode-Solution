class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
        if(k%n==0) return;
        k%=n;
        vector<int> v(n);
        int count =0;
        for(int i=n-k;i<n;i++) {v[count++]=nums[i];}
        for(int i=0;i<n-k;i++) v[count++] = nums[i];
        nums = v;
        
        
    }
};