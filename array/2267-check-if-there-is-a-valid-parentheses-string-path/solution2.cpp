class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;

        int max_bal = (n + m) / 2;

        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(max_bal + 1, false)));
        dp[0][0][1] = true;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                for (int bal = 0; bal <= max_bal; bal++) {
                    if (!dp[r][c][bal]) continue;

                    if (r + 1 < n) {
                        int next_bal = bal + (grid[r + 1][c] == '(' ? 1 : -1);
                        if (next_bal >= 0 && next_bal <= max_bal) {
                            dp[r + 1][c][next_bal] = true;
                        }
                    }

                    if (c + 1 < m) {
                        int next_bal = bal + (grid[r][c + 1] == '(' ? 1 : -1);
                        if (next_bal >= 0 && next_bal <= max_bal) {
                            dp[r][c + 1][next_bal] = true;
                        }
                    }
                }
            }
        }
        return dp[n - 1][m - 1][0];
    }
};