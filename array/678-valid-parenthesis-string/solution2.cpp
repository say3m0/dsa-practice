class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openBrackets;
        stack<int> stars; 

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else { 
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false; 
                }
            }
        }

        while (!openBrackets.empty() && !stars.empty()) {
            if (openBrackets.top() > stars.top()) {
                return false;
            }
            openBrackets.pop();
            stars.pop();
        }
        return openBrackets.empty();
    }
};