class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incre=1,decre=1,ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ans=max({ans,incre,decre});
                incre=1;
                decre=1;
            }
            if(nums[i]<nums[i+1])incre++;
            else {
                ans=max({ans,incre,decre});
                incre=1;
            }
            if(nums[i]>nums[i+1])decre++;
            else {
                ans=max({ans,incre,decre});
                decre=1;
            }
        }
        return max({ans,incre,decre});
    }
};