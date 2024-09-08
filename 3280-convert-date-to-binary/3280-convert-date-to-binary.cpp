class Solution {
    private:
    string numberToBinary(int n){
        string binaryString = "";
        while(n>0){
            binaryString=binaryString + to_string(n%2);
            n/=2;
        }
        reverse(binaryString.begin(),binaryString.end());
        return binaryString;
    }
public:
    string convertDateToBinary(string date) {
        string ans = "";
        string temp = "";
        int n = date.size();
        for(int i=0;i<n;i++){
            if(date[i]!='-'){
                temp+=date[i];
            }
            else{
                int num = stoi(temp);
                string convertedBinary = numberToBinary(num);
                temp = "";
                ans+=convertedBinary+"-";
                
            }
        }
        int num = stoi(temp);
        string convertedBinary = numberToBinary(num);
        temp = "";
        ans+=convertedBinary;
        
        return ans;
    }
};