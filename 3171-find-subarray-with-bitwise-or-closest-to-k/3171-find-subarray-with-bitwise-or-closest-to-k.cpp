#define ll long long
#include<bits/stdc++.h>
using namespace std;
class ST{
public:
    vector<ll> seg;
    ST(ll n){
        seg.resize(4*n+1); // +1 for beign on safe side
 
    }
public:
    void build(ll ind,ll low,ll high,vector<int>& arr){
 
        //base case
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low+high) >> 1;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = (seg[2*ind+1]|seg[2*ind+2]);
    }
public:
    //Time to process queries
    ll query(ll ind,ll low,ll high,ll l,ll r){
        if (r < low or high < l)
            return 0;
 
        if (low >= l and high <= r)
            return seg[ind];
        ll mid = (low+high) >> 1;
        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);
        return (left|right);

    }};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        ST st(nums.size()+1);
        st.build(0,0,nums.size()-1,nums);
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int low = i,high = n-1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                int rangeVal = st.query(0,0,n-1,i,mid);
                //cout<<rangeVal<<endl;
                ans = min(ans,abs(rangeVal-k));
                if(rangeVal < k)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid-1;
                }
                
            }
        }
        return ans;
    }
};










