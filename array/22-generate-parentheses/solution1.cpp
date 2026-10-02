class Solution {
public:
    vector<string>valid;
    void generate(string &s, int open, int close){
        if(close==0 && open==0) {
            valid.push_back(s);
            return;
        }
        if(open>0){
        s.push_back('(');
        generate(s,open-1,close);
        s.pop();
        }
        if(close>0 && open<close){
        s.push_back(')');
        generate(s,open,close-1);
        s.pop();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s,n,n);
        return valid;
    }
};