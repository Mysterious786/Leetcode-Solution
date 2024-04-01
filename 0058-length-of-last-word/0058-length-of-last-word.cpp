class Solution {
public:
    int lengthOfLastWord(string s) {
      int count = 0;
    int i=s.length()-1;
        while(s[i]==' '){
            i--;
        }
    while (i >= 0 and s[i--] != ' ') // counting ending word characters
        count++;

    return count;
    }
};