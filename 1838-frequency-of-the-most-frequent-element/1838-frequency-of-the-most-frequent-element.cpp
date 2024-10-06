class Solution {
    private:
    int binarySearch(vector<long long>& pref,int i,int ele,int k)
    {
        int start = 0;
        int end = i;
        int ans = i;
        while(start <= end)
        {
            long long mid = (start+end)>>1;
            long long windowSize = (i-mid+1);
            long long originalSum = pref[i] - (mid>0?pref[mid-1]:0);
            long long neededSum  = windowSize*ele;
            long long req = neededSum - originalSum;
            if(req > k) start = mid+1;
            else{
                ans = mid;
                end = mid-1;
            }
        }
        return (i-ans+1);
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = size(nums);
        sort(begin(nums),end(nums));
        vector<long long> pref(n,0);
        pref[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i] = pref[i-1] + nums[i];
        }
        int ans = 1;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,binarySearch(pref,i,nums[i],k));
        }
        return ans;
    }
};