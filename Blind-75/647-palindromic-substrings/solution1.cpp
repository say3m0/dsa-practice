
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int j = i, k = i;
            while(j >= 0 && k < n && s[j] == s[k]) {
                count++;
                j--;
                k++;
            }
            j = i;
            k = i + 1;
            while(j >= 0 && k < n && s[j] == s[k]) {
                count++;
                j--;
                k++;
            }
        }
        return count;
    }
};
