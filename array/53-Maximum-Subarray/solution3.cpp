class Solution {
public:

    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN;
        int sum = 0;
        for(int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        int rightSum = INT_MIN;
        sum = 0;
        for(int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }


    int solve(vector<int>&v, int left, int right){
        if(left == right) return v[left];
        int mid=left+(right-left)/2;
        int leftMax=solve(v,left,mid);
        int rightMax=solve(v,mid+1,right);
        int crossMax=maxCrossingSum(v,left,mid,right);

        return max({leftMax,rightMax,crossMax});

    }
    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};