class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')st.push(s[i]);
            else{
                if(st.empty()) return false;
                char current=st.top();
                if((s[i] == ')'&&current != '(')||(s[i] == '}'&&current!='{')||(s[i]== ']'&&current!='['))return false;
                else st.pop();
            }
        }
        if(!st.empty()) return false;

        return true;
    }
};