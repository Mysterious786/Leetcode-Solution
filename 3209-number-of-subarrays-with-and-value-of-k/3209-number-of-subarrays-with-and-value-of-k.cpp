#define ll long long

class ST {
public:
    vector<ll> seg;
    ST(ll n) {
        seg.resize(4 * n + 1, -1); 
    }
public:
    void build(ll ind, ll low, ll high, vector<ll>& arr) {
        //base case
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = (seg[2 * ind + 1] & seg[2 * ind + 2]);
    }
public:
    //Time to process queries
    ll query(ll ind, ll low, ll high, ll l, ll r) {
        if (r < low || high < l)
            return -1; // Identity for AND operation is -1

        if (low >= l && high <= r)
            return seg[ind];
        ll mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return (left & right);
    }
public:
    void update(ll ind, ll low, ll high, ll i, ll val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        ll mid = (low + high) >> 1;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val);
        }
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = (seg[2 * ind + 1] & seg[2 * ind + 2]);
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        ST st(n + 1);
        vector<ll> nu(n);
        for (int i = 0; i < n; i++) nu[i] = nums[i];
        st.build(0, 0, n - 1, nu);

        for (int i = 0; i < n; i++) {
            ll val = st.query(0, 0, n - 1, i, n - 1);
            if (val > k) continue;
            ll pos1 = -1, pos2 = -1;
            ll low = i, high = n - 1;

            while (low <= high) {
                ll mid = (low + high) >> 1;
                if (st.query(0, 0, n - 1, i, mid) <= k) {
                    pos1 = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            //again
            low = i, high = n - 1;
            while (low <= high) {
                ll mid = (low + high) >> 1;
                if (st.query(0, 0, n - 1, i, mid) >= k) {
                    pos2 = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            if (pos1 != -1 && pos2 != -1) {
                ans = ans + 1ll * (pos2 - pos1 + 1);
            }
        }
        return ans;
    }
};
