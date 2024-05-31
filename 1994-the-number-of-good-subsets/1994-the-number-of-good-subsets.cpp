class Solution {
    const static long long MOD = 1e9+7;
private:
    long long find(int ind,int mask,vector<int>& unique,map<int,int>& primeMask,vector<int>& v,map<int,int>& freq){
        if(ind>=unique.size()){
            long long count =1;
            for(auto it : v) count = (count%MOD*freq[it]%MOD)%MOD;
                return count;
        }
        long long ans = find(ind+1,mask,unique,primeMask,v,freq);
        // checking whether this alredy present if yes dont take
        if((primeMask[unique[ind]]&mask) == 0){
            v.push_back(unique[ind]);
            ans = (ans%MOD + find(ind+1,mask^primeMask[unique[ind]],unique,primeMask,v,freq))%MOD;
            //backtracking and removing
            v.pop_back();
        }
         return ans;
    }
   
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int n = nums.size();
        // things we need to do
        //1. count number of one and skip this iteration
        //2. create frequency map prime map and prime map mask
        //3. frquency map will store the frequncy of the nums except 1
        //4. prime map will store the index of the prime number of vector say prime
        //5. prime mask map will store the mask like whether to make this element I hae selected what elements 
        // Example of above :
                        // 6 ---> 2*3 === 011
        // ans will be freq of each element prodct present in the subset 
        // atlast we need to put the remaining one in the subset
        // suppose there are 3 ones so asnwer wiil be ans+=(3c1+3c2+3c3);
        //At last return the answer


        //lets make the vector of primes
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        int sz = primes.size();

        // lets store the index as the value which will help us in finding the mask
        map<int,int> primeInd;
        for(int i=0;i<sz;i++) primeInd[primes[i]] = i;

        int ones = 0; // for counting number of 1's 

        set<int> s;// used in order to not store the duplicates, excpet 1 stores everything

        map<int,int> freq; // storing the frequency of each num except 1
        map<int,int> primeMasky;// store mask value for each valid number
        for(auto it : nums){
            // condition to count and skip one...
            if(it==1){
                ones++;
                continue;
            }
            bool take = true; // true signifies add this number as its follows all conditon inorder to be added
            int curr = it; // current index value that is nums[currIndex]
            int primeMask = 0; // mask inorder to know what numbers from prime we have pick using it for prime factorization stuff
            for(int j=2;j*j<=it;j++){
                int count =0;
                while(curr%j==0){
                    curr/=j;
                    count++;
                }
                if(count > 0 and count!=1){
                    take = false;
                }
                else if(count==1){
                    primeMask = primeMask ^ (1<<primeInd[j]);
                }

            }
            // if some curr value left except 1
            if(curr!=1){
                primeMask = primeMask ^ (1<<primeInd[curr]);
            }
            if(take){
                s.insert(it);
                freq[it]++;
                primeMasky[it] = primeMask;

            }

        }

        vector<int> v; // for pick non pick operation 
        vector<int> uniqueElement(s.begin(),s.end()); // unique values
        long long ret = find(0,0,uniqueElement,primeMasky,v,freq); 

        // removing empty subset
        ret = (ret-1+MOD)%MOD;
        long long onesAns = 1;
        for(int i=0;i<ones;i++){
            onesAns= (onesAns%MOD * 2%MOD)%MOD;
        }
        // removing one as nc1+nc2+nc3+.....+ncn==2^n-1
        ret = (ret%MOD + ((onesAns-1+MOD)%MOD*ret%MOD))%MOD;
        return ret;

    }
};