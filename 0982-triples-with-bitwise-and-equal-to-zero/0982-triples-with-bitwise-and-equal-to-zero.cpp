class Solution {
//     int countTriplets(vector<int>& A, int cnt = 0) {
//   unordered_map<int, int> tuples;
//   for (auto a : A)
//     for (auto b : A) ++tuples[a & b];
//   for (auto a : A)
//     for (auto t : tuples)
//       if ((t.first & a) == 0) cnt += t.second;
//   return cnt;
// }
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums){
            for(auto i : nums){
                mp[i&it]++;
            }
        }
        int count =0;
        for(auto it : nums){
            for(auto m : mp){
                if((m.first&it) == 0) count+=m.second;
            }
        }
        return count;
    }
};