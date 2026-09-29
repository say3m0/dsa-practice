class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if ((n + m - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;

        int max_bal = (n + m) / 2;
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(max_bal + 1, false)));

        queue<tuple<int, int, int>> q;

        q.push({0, 0, 1});
        visited[0][0][1] = true;

        int dr[] = {1, 0};
        int dc[] = {0, 1};

        while (!q.empty()) {
            auto [r, c, bal] = q.front();
            q.pop();

            if (r == n - 1 && c == m - 1 && bal == 0) {
                return true;
            }

            for (int i = 0; i < 2; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < n && nc < m) {
                    int next_bal = bal + (grid[nr][nc] == '(' ? 1 : -1);

                    if (next_bal >= 0 && next_bal <= max_bal && !visited[nr][nc][next_bal]) {
                        visited[nr][nc][next_bal] = true;
                        q.push({nr, nc, next_bal});
                    }
                }
            }
        }
        return false;
    }
};