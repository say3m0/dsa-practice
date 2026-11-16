class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0, start = 0;
        for(int i = 0; i < n; i++) {
            int j = i, k = i;
            while(j >= 0 && k < n && s[j] == s[k]) {
                int len = k - j + 1;
                if(len > maxLen) {
                    maxLen = len;
                    start = j;
                }
                j--;
                k++;
            }
            j = i;
            k = i + 1;
            while(j >= 0 && k < n && s[j] == s[k]) {
                int len = k - j + 1;
                if(len > maxLen) {
                    maxLen = len;
                    start = j;
                }
                j--;
                k++;
            }
        }
        return s.substr(start, maxLen);
    }
};