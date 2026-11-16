class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        long long actual=(nums.size()*(nums.size()+1))/2;
        return actual-sum;
    }
};