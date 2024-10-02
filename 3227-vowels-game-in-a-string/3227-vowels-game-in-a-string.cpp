class Solution {
public:
    bool doesAliceWin(string s) {
        int vows = 0;
        for(auto it : s)
        {
            if(it=='a' || it=='e'|| it=='i' || it=='o' || it=='u') vows++;
        }
        if(vows==0) return false;
        return true;
        
    }
};