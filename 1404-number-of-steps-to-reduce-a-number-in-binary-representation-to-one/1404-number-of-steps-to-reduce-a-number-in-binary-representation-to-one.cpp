class Solution {
public:
    int numSteps(string s) {
        int end = s.size()-1;
        int carry=0,count =0;
        while(end>0){
            //case 1
            if(s[end]-'0' + carry == 0){
                carry=0;
                count++;//divide
            }
            else if(s[end]-'0' + carry==2){
                carry = 1;
                count++;
            }
            else{
                count+=2;
                carry=1;
            }
            end--;
        }
        if(carry==1) count++;
        return count;
        
    }
};