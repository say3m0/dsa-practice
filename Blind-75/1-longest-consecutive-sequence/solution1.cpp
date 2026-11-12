class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int cnt=1,ans=1;
        set<int>s;
        for(auto u:nums)s.insert(u);
        for(auto it=s.begin();it!=s.end();it++){
            auto next_ele=next(it);
            if(next_ele == s.end()) break;
            if((*next_ele-*it)==1){
                cnt++;
            }
            else {
            ans=max(ans,cnt);
            cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};