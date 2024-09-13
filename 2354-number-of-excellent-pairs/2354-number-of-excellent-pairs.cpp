//2354


class Solution {
private:
	int bitsCount(int n)
	{
		long long ans = 0;
		while(n>0)
		{
            int rem = n%2;
			ans = ans + rem;
			n/=2;
		}
		return static_cast<int>(ans);
	}
public:
    long long countExcellentPairs(vector<int>& num, int k) {
        set<int> st;
        for(auto it : num) st.insert(it);
        vector<int> nums(st.begin(),st.end());
        vector<int> bits;
        int n = nums.size();
        for(auto it : nums) bits.push_back(bitsCount(it));
        sort(bits.begin(),bits.end());
    int left = 0;
    int right = n-1;
    long long ans = 0;
    while(left<n and right>=0)
    {
    	long long tot = bits[left] + bits[right];
    	if(tot < k)
    	{
    		left++;
    	}
    	else
    	{
    		ans = ans + (n-left);
            
    		right--;
    	}
    }
    return ans;

    }
};