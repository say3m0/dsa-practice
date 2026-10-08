//just find out the outer bound
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string x;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;

                if (cnt > 1)
                    x += s[i];
            }
            else {
                if (cnt > 1)
                    x += s[i];
                cnt--;
            }
        }
        return x;
    }
};