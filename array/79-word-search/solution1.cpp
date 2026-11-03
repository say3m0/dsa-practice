class Solution {
public:
    int m,n;
    
    bool find(vector<vector<char>> &board,int i,int j,string &word,int idx){
        if(idx==word.size())return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(board[i][j]!=word[idx] ) return false;
        char ch=board[i][j];
        board[i][j]='$';

        bool found=(find(board,i+1,j,word,idx+1)||
        find(board,i-1,j,word,idx+1)||
        find(board,i,j+1,word,idx+1)||
        find(board,i,j-1,word,idx+1)
        )
;
        board[i][j]=ch;
        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        if(m*n<word.size()) return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(find(board,i,j,word,0)) return true;
                }
            }
        }
        return false;
    }
};