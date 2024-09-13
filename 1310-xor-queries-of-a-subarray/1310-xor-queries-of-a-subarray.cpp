#define ll long long
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
		seg[ind] = (seg[2*ind+1]^seg[2*ind+2]);
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
        return (left^right);
	}
public:
	void update(ll ind,ll low,ll high,ll i,ll val){
		if(low==high){
			seg[ind] = val;
			return;
		}
		ll mid = (low+high) >> 1;
		if(i<=mid){
			update(2*ind+1,low,mid,i,val);
		}
		else update(2*ind+2,mid+1,high,i,val);
		seg[ind] = (seg[2*ind+1]^seg[2*ind+2]);
	}
 
};





class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        ST st(n);
        st.build(0,0,n-1,arr);
        vector<int> ans;
        for(auto it : queries)
        {
            int l = it[0];
            int r = it[1];
            int ret = st.query(0,0,n-1,l,r);
            ans.push_back(ret);
        }
        return ans;
    }
};