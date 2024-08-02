class Solution {
private:
    long long find(int mid,vector<int>& piles){
        long long count = 0;
        for(auto it : piles){
            count+=(it/mid)+(it%mid!=0);
        }
        return count;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int  n = piles.size();
        long long ans=0;
        long long low = 1;
        long long high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = (low+high)/2;
            long long time = find(mid,piles);
            if(time<=h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};