class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
        
        for(int i=0;i<size(s);i++)
        {
            if(s[i]!='*')
            {
                pq.push({s[i],-i});
            }
            else
            {
                int ind = pq.top().second;
                ind = -ind;
                s[ind] = '#';
                pq.pop();
            }
        }
        string st;
        for(auto it : s)
        {
            if(it!='*' and it!='#') st.push_back(it);
        }
        return st;
        
    }
};