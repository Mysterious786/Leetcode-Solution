class Solution
{
    public:
        int minOperations(vector<int> &nums)
        {
            map<int, int> mp;
            for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;
            int count = 0;
            for (auto it: mp)
            {
                int vl = it.second;
                if (vl < 2) return -1;

                if ((vl % 2 == 0 && vl % 3 == 0) || vl % 3 == 0) count += (vl / 3);

                else
                {
                    int rem = vl % 3;
                    if (rem == 2)
                    {
                        count += (vl / 3) + 1;
                    }
                    else if (rem == 1)
                    {
                        int upto = vl / 3;
                        upto--;
                        count += upto + 2;
                    }
                    else return -1;
                }
            }
            return count;
        }
};