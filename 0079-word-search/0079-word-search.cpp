class Solution {
    private:
    bool checkIt(vector<vector<char>>& board,int i,int j,int len, string word,int& n,int &m){
        //Base cases
        if(word.length() == len) return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[len]){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';
        bool foundUp = checkIt(board,i-1,j,len+1,word,n,m);
        bool foundDown = checkIt(board,i+1,j,len+1,word,n,m);
        bool foundLeft = checkIt(board,i,j-1,len+1,word,n,m);
        bool foundRight = checkIt(board,i,j+1,len+1,word,n,m);
        bool finalAns = foundUp || foundDown || foundRight || foundLeft;
        board[i][j] = temp;
        return finalAns;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && checkIt(board,i,j,0,word,n,m)) return true;
            
            }
        }
        return false;
    }
};