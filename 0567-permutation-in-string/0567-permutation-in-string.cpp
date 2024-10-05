class Solution {
public:
    bool checkInclusion(string s1, string s2) {

       sort(s1.begin(),s1.end());
      int size1=s1.length();
      int size2=s2.length();
      if(size1>size2) return false;
      int i=0;
      for(int i=0;i<=size2-size1;i++){
        string s=s2.substr(i, size1);
        sort(s.begin(),s.end());
        if(s1==s) return true;
        
      }
      return false;
    }
};