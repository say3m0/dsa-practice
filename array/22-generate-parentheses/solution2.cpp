class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // tuple structure: {current_string, open_rem, close_rem}
        queue<tuple<string, int, int>> q;
        q.push({"", n, n});

        while (!q.empty()) {
            auto [s, open, close] = q.front();
            q.pop();

            if (open == 0 && close == 0) {
                result.push_back(s);
            }
            if (open > 0) {
                q.push({s + "(", open - 1, close});
            }
            if (close > open) {
                q.push({s + ")", open, close - 1});
            }
        }
        return result;
    }
};