class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty())cnt++;
                if(i==s.size()-1)cnt++;
                if(i<s.size()-1 && s[i+1]!=')')cnt++;
                else i++;
                if(!st.empty())st.pop();
            }
        }
        if(!st.empty())cnt+=2*st.size();
        return cnt;
    }
};