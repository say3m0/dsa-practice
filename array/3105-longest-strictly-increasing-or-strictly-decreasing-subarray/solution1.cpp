class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incre=1,decre=1,ans=0;
        if(nums.size()==1)return 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                incre=1;
                decre=1;
            }
            if(nums[i]<nums[i+1]){
                incre++;
                decre=1;
            }
            if(nums[i]>nums[i+1]){
                decre++;
                incre=1;
            }
            ans=max({ans,incre,decre});
        }
        return ans;
    }
};