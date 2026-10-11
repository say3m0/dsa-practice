class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        for(auto u:nums){
            str.push_back(to_string(u));
        }
        sort(str.begin(),str.end(),[](const string &a,const string &b){
            return (a+b) > (b+a);
        });
        if(str[0]=="0") return "0";
        string result="";
        for(auto u:str){
            result+=u;
        }
        return result;
    }
};