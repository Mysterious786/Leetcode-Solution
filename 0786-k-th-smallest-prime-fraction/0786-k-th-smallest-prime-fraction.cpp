class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                double store = (double)arr[i]/arr[j];
                pq.push(make_pair(store,make_pair(arr[i],arr[j])));
            }
        }
    }
    k--;
    while(k--){
        pq.pop();
    }
    vector<int> v(2,0);
    v[0] = pq.top().second.first;
    v[1] = pq.top().second.second;
    return v;
    }
};