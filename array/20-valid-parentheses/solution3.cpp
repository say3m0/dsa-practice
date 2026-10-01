//Imitting behavior of a stack by pointer
class Solution {
public:
    bool isValid(string s) {
        int top=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                top++;
                s[top] = s[i];
            }
            else{
                if(top<0) return false;
                else if((s[i] == ')' && s[top] != '(')||(s[i] == '}' && s[top] != '{')||(s[i] == ']' && s[top] != '[')) return false;
                top--;
            }
        }
        return top==-1;
    }
};