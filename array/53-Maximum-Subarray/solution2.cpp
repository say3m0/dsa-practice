class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int freqSum=0,maxSum=-INT_MIN;
        for(int i=0;i<nums.size();i++){
            freqSum+=nums[i];
            maxSum=max(maxSum,freqSum);
            if(freqSum<0)freqSum=0;
        }
        return maxSum;
    }
};