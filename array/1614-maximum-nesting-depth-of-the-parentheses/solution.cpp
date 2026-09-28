class Solution {
public:
    int maxDepth(string s) {
        int count=0,ans=-1;
        for(int i=0;i<s.size();i++){
            ans=max(ans,count);
            if(s[i]=='(')count++;
            else count--;
        }
        return ans;
    }
};

//Another way

int ans = 0, depth = 0;
for(auto ch : s){
    depth += (ch == '(') - (ch == ')');
            ans = max(ans, depth);
        }
return ans;
