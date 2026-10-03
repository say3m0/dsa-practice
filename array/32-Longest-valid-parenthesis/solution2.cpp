class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0;
        int max_len=0;
        //from left to right
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')left++;
            else right++;

            if(left<=right){
                max_len=max(max_len,2*right);
            }else if (right>left){
                left=0;
                right=0;
            }
        }
        left=0;
        right=0;
        //from right to left
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(')left++;
            else right++;

            if(right<=left){
                max_len=max(max_len,2*left);
            }else if (right<left){
                left=0;
                right=0;
            }
        }
        return max_len;
    }
};