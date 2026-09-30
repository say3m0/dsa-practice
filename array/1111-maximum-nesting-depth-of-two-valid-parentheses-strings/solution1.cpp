class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<pair<char,int>>st;
        vector<int>ans(seq.size(),0);
        //jehetu ami ekane stack teke kono value retrieve kore kaj korcina so stack chara manually o kora jai
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                st.push({seq[i],i});
                ans[i]=st.size()%2;
            }
            else{
                ans[i]=st.size()%2;
                st.pop();
            }
        }
        return ans;
    }
};