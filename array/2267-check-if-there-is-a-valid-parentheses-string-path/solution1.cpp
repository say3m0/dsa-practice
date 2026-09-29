//Top-down approach

class Solution {
public:
    int memo[105][105][210]; // row,col,balance
    int n,m,balance;
    bool dfs(int r,int c,int balance,vector<vector<char>>&grid){
            balance+=grid[r][c]=='('? 1 : -1;
            if(balance<0) return false;
            if(r==n-1 && c==m-1) return balance==0;
            if(memo[r][c][balance]!=-1) return memo[r][c][balance];
            //down
            if(r+1<n && dfs(r+1,c,balance,grid)) return memo[r][c][balance]=1;
            else if(c+1<m && dfs(r,c+1,balance,grid)) return memo[r][c][balance]=1;
            return memo[r][c][balance]=0;
        }
        
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if((n+m-1)%2!=0) return false;
        if(grid[0][0]==')'||grid[n-1][m-1]=='(') return false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<=(n+m);k++){
                    memo[i][j][k]=-1;
                }
            }
        }
        return dfs(0,0,0,grid);
}
};