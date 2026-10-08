class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string x;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                if(st.size()>1){
                    x+=s[i];
                }
            }
            else{
                if(st.size()>1){
                    x+=s[i];
                }
                st.pop();
            }
        }
        return x;
    }
};