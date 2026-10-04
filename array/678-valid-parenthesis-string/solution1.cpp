class Solution {
public:
    bool checkValidString(string s) {
        int open_count = 0;
        for (char c : s) {
            if (c == '(' || c == '*') {
                open_count++;
            } else { // c == ')'
                open_count--;
            }
            if (open_count < 0) {
                return false;
            }
        }

        int close_count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                close_count++;
            } else { // s[i] == '('
                close_count--;
            }
            if (close_count < 0) {
                return false;
            }
        }
        return true;
    }
};