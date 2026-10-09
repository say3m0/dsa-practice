class Solution {
public:
    int minInsertions(string s) {
        int cnt=0,open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')open++;
            else{
                if(open==0)cnt++;
                if(i==s.size()-1)cnt++;
                if(i<s.size()-1 && s[i+1]!=')')cnt++;
                else i++;
                if(open>0)open--;
            }
        }
        cnt+=2*open;
        return cnt;
    }
};