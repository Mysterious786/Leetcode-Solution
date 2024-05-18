class Solution {
    private: 
    void rev(vector<int>& nums,int start,int end){
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k%=n;
        if(k==0) return;
        rev(nums,0,n-k-1);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);
        
        
    }
};