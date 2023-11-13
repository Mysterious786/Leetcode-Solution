class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it : arr) mp[it]++;
        int pre = -1;
        for(int i=1;i<=100000;i++){
            if(k==0) return pre; 
            if(mp.find(i)==mp.end()){ k--; pre=i;}
        }
        return -1;
    }
};