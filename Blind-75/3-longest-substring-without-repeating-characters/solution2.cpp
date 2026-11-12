class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0, n = s.size();
        vector<int>v(256,-1);
        while(i<n && j<n) {
            if(v[s[j]]!=-1) {
                if(v[s[j]]>=i){
                    i=v[s[j]]+1;
                }
            }
            ans = max(ans, j - i + 1);
            v[s[j]]=j;
            j++;
        }
        return ans;
    }
};