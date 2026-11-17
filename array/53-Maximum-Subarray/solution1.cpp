class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minSum=0,prepSum=0,ans=-100000;
        for(int i=0;i<nums.size();i++){
            prepSum+=nums[i];
            ans=max(ans,prepSum-minSum);
            minSum=min(minSum,prepSum);
        }
        return  ans;
    }
};