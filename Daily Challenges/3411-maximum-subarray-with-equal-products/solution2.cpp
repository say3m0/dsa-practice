class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int last[11];
        fill(last, last + 11, -1);

        int left = 0, ans = 2;
        int primes[] = {2, 3, 5, 7};

        for (int right = 0; right < n; right++) {

            for (int p : primes) {
                if (nums[right] % p == 0) {
                    left = max(left, last[p] + 1);
                }
            }   
            for (int p : primes) {
                if (nums[right] % p == 0) {
                    last[p] = right;
                }
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
