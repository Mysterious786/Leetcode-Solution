class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
        int count =0;
        int start = 0;
        for(int i=0;i<n2;i++){
            for(int j=start;j<n1;j++){
                if(arr1[j]==arr2[i]){
                    swap(arr1[start],arr1[j]);
                    count++;
                    start++;
                }
            }
        }
        sort(arr1.begin()+count,arr1.end());
        return arr1;
    }
};