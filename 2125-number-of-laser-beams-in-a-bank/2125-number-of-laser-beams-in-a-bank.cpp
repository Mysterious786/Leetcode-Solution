class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int size = bank.size();
        vector<int> v(size,0);
        int ans =0;
        for(int i=0;i<size;i++){
            int count =0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j] == '1') count++;
            }
            v[i] = count;
        }
       
        for(int i=0;i<v.size()-1;i++){
            if(v[i] == 0){}
             else if(v[i+1] == 0) {v[i+1]+=v[i];}
            else{
            
            
            
            int val = v[i+1];
           
            ans+=(v[i]*val);
            }
        }
        return ans;
        
    }
};