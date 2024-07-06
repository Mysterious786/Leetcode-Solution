class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count =0;
        for(int i=0;i<n;i++){
            int prev = colors[(i-1+n)%n];
            int curr = colors[i%n];
            int next = colors[(i+1)%n];
            if((prev==next) and next!=curr) count++;
        }
        return count;
        
    }
};