class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long count =0;
        long long sum =0;
        for(int i=happiness.size()-1;i>=0 and k>0;i--){
            if(happiness[i]-count <=0) break;
            sum+=(happiness[i]-count);
            count++;
            k--;
            
        }
        return sum;
    }
};