#define ll long long
class Solution {
private:
    bool checkFrame( unordered_map<string,int>um, string frStr, int smlFr)
{

    for(int i=0 ; i <= frStr.size()-smlFr; i+= smlFr)
    {
        string ss = frStr.substr(i,smlFr) ;
        if(um.find(ss) != um.end())
        {
            um[ss]-- ;
            if(um[ss] < 0 ) return false ;
        }
        else return false ;
    }
    return true ;
}
    public:
vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int>ans ;
    unordered_map<string,int>um ;

    for(string word : words ) um[word]++ ;
    int bigFr = words.size()*words[0].size() ;
    int smlFr = words[0].size() ;

    if( s.size() < bigFr) return {} ;

    for(int i=0 ; i <= s.size()-bigFr ; i++)
    {
        if(checkFrame(um, s.substr(i,bigFr),smlFr))
        {
            ans.push_back(i) ;
        } 
    }
    return ans;

}
};
