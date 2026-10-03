//Solve this using top-down approach

class Solution {
    vector<int>dp;
    int max_len = 0;
    int solve(int i,string &s){
        if(i<0) return 0 ;

        if(dp[i]!=-1)return dp[i];
        solve(i-1,s);

        if(s[i]=='(') return dp[i]=0;

        int ans=0;
        if(i-1 >=0 && s[i-1]=='('){
            ans=2+solve(i-2,s);//this new pair able to add with previous valid pair
        }
        else if(i-1 >=0 && s[i-1]==')'){
            int len = solve(i-1,s);
            int prev_idx=i-len-1;//prev_idx মূলত বর্তমান ')' এর জন্য সম্ভাব্য ম্যাচিং '(' ব্র্যাকেটের পজিশন খুঁজে বের করে। যদি সেখানে সত্যি কোনো '(' থেকে থাকে, তবে পুরো নেস্টেড অংশটা মিলে বড় একটি ভ্যালিড ব্র্যাকেট সিকোয়েন্স তৈরি হয়

            if(prev_idx>=0 && s[prev_idx]=='('){
                ans= len+2+solve(prev_idx-1,s);
            }
        }
        max_len= max(max_len,ans);
        return dp[i]=ans;
    }


public:
    int longestValidParentheses(string s) {
       int n=s.size();
       dp.assign(n,-1);

       solve(n-1,s);
        return max_len;
        
    }
};