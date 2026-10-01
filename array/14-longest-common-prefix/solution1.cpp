class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        for(int i=0;i<str[0].length();i++){
            for(int j=1;j<str.length();j++){
                if(i==str[j].length()||str[0][i]!=str[j][i]){
                    return str.substr(0,i);
                }
            }
        }
        return str[0];
    }
};