class Solution {
private:
    vector<int> nextGreat(vector<pair<int,int>>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(auto it : nums){
            int ind = it.second;
            while(!st.empty() and st.top() < ind){
                ans[st.top()] = ind;
                st.pop();
            }
            st.push(ind);
        }
        return ans;
    }
public:
    int oddEvenJumps(vector<int>& arr) {
       //1. create sort array
        int n = arr.size();
        vector<pair<int,int>> v1,v2;
        for(int i=0;i<n;i++){
            v1.push_back({arr[i],i});
            v2.push_back({-arr[i],i});
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        vector<int> nextGreater = nextGreat(v1);
        vector<int> nextSmaller = nextGreat(v2); // sorted via neg 
        vector<int> oddStart(n,0),evenStart(n,0);
        oddStart[n-1]=evenStart[n-1]=1; // base case
        for(int i=n-2;i>=0;i--){
            if(nextGreater[i]!=-1){
                oddStart[i] = evenStart[nextGreater[i]];
            }
            if(nextSmaller[i]!=-1){
                evenStart[i] = oddStart[nextSmaller[i]];
            }
        }

        return accumulate(oddStart.begin(),oddStart.end(),0);


    }
};