#define ll long long
class Solution {
public:
    // Goal?
    // To manage a set with top x element after each iteration and their sum
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        // vector to return
        vector<ll> ans;

        // multisets decreasing to increasing
        // top will store top x frequency num
        // bottom will store rest k-x frequency num in window k
        multiset<pair<ll,ll>,greater<pair<ll,ll>>> top,bottom;

        // map to store frequency
        map<ll,ll> cnt;

        int n = size(nums); // size of array

        ll sum  = 0; // will be pushed in ans array

        for(int i=0;i<n;i++)
        {
            // check the count

            ll count = cnt[nums[i]]; // count/ frequency of num in map

            // if exist
            if(count)
            {
                auto check = bottom.find({count,nums[i]});
                if(check != end(bottom)) // if present 
                {
                    bottom.erase(check); // erase simply from bottom set
                }
                else
                {
                    // if not that means it is in my top set
                    top.erase({count,nums[i]});
                    sum-=count*nums[i];
                }
            }
            // increase the frequency, insert and add to sum
            cnt[nums[i]] = count + 1;
            top.insert({count+1,nums[i]});
            sum+=(count+1)*nums[i];

            if(top.size() > x) // more than x top in top set
            {
                // I will be removing the last element from my top array
                auto lastOfTop = prev(end(top));
                sum-=(lastOfTop->first*lastOfTop->second);
                bottom.insert({lastOfTop->first,lastOfTop->second});
                top.erase(lastOfTop);
            }

            if(i>=k) // window greater than size k
            {
               // to do...
                ll extraNumCount = cnt[nums[i-k]];
                // if its in my bottom that siginifes it it not contributing to my sum
                auto check = bottom.find({extraNumCount,nums[i-k]});
                if(check != end(bottom))
                {
                    // I got this and will remove this only from here
                    bottom.erase(check);

                }
                else
                {
                    auto it = top.find({extraNumCount,nums[i-k]});
                     sum-=(it->first*it->second);
                    top.erase(it);

                }
                if(extraNumCount > 1) // if it not going to be zero on rmeoval of one frequency then I can add
                {
                    bottom.insert({extraNumCount-1,nums[i-k]});
                }
               cnt[nums[i-k]]--;
                if(top.size() < x)
                {
                    auto topOfBottom = begin(bottom);
                    if(topOfBottom!=end(bottom))
                    {
                        sum+=(topOfBottom->first*topOfBottom->second);
                        top.insert({topOfBottom->first,topOfBottom->second});
                         bottom.erase(topOfBottom);
                    }
                }


            }

            if(i+1 >= k) // end goal since we will return this array
            {
                ans.push_back(sum);
            }

        }
        // return ans

        return ans;
    }
};