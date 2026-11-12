class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.size(), boundary = 0;
        map<char, int> mp;
        for(int i = 0; i < n; i++) {
            if(!mp.count(s[i])) {
                mp[s[i]] = i;
            }
            else {
                boundary = max(boundary, mp[s[i]] + 1);
                mp[s[i]] = i;
            }
            ans = max(ans, i - boundary + 1);
        }
        return ans;
    }
};