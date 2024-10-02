class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
            int count =1;
            for(auto it : arr){
                    mp[it]++;
            }
            for(auto it : mp){
                    mp[it.first] = count;
                    count++;
            }
            vector<int> ans;
            for(int i=0;i<arr.size();i++){
                  ans.push_back(mp[arr[i]]);  
            }
            return ans;
    }
};