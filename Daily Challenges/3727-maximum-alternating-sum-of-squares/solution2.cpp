
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        for (int &x : nums) {
            x = abs(x);
        }
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long sq = 1LL * nums[i] * nums[i];
            if (i < mid) {
                ans -= sq;
            } else {
                ans += sq;
            }
        }
        return ans;
    }
};
