class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string,int> deadMap;
        map<string,int> firstOcurrence;
        for(auto it : deadends) deadMap[it]++;
        if(deadMap.find("0000")!=deadMap.end() || deadMap.find(target)!=deadMap.end()) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty())
        {   
            auto it = q.front();
            q.pop();
            int currentTurns = it.second;
            string currentPattern = it.first;
            if(currentPattern == target)
            {
                return currentTurns;
            }
            int size = currentPattern.size();
            for(int i=0;i<size;i++)
            {
                char original = currentPattern[i];
                for(auto j : {-1,1})
                {
                    currentPattern[i] = (original-'0'+j+10)%10+'0';
                    if(firstOcurrence.find(currentPattern) == firstOcurrence.end() and deadMap.find(currentPattern) == deadMap.end())
                    {
                        firstOcurrence[currentPattern]++;
                        q.push({currentPattern,currentTurns+1});
                    }
                }
                currentPattern[i] = original;
            }

        }
        return -1;
    }
};