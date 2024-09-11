class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> zeroInd;
        int ans = 0;
        int n = size(s);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') 
            {
                zeroInd.push_back(i);
            }
        }
        if(zeroInd.size()==0) return n*(n+1)/2;
        int zero_ind = 0;
        for(int l =0;l<n;l++)
        {
            while(zero_ind<zeroInd.size() and l > zeroInd[zero_ind]) zero_ind++;
            vector<int> validZero;
            for(int z = zero_ind;z<zeroInd.size() and z < (zero_ind+201);z++)
            {
                validZero.push_back(zeroInd[z]);
            }
            validZero.push_back(n);
            int zro = 0;
            int last = l;
            for(auto it : validZero)
            {
                int minOnes = zro*zro;
                int minInd = max(last,minOnes+l+zro-1);
                if(minInd < it)
                {
                    ans+=(it-minInd);
                }
                last = it;
                zro++;
            }
        }
        return ans;
    }
};