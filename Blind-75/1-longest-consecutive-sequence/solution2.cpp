class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int cnt=1,ans=0;
        unordered_set<int>s;
        for(auto u:nums){
            s.insert(u);
        }
        for(auto u:s){
            if(s.count((long long)u-1))continue;
            else{
                int j=1;
                while(s.count((long long)u+j)){
                    cnt++;
                    j++;
                }
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        return ans;
    }
};