//THREE POINTER

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int i = 0, j = 1, k = 2;
        int count = 0;
        int n = nums.size();

        while (i < n && j < n && k < n) {
            while (j < n && nums[j] - nums[i] < diff) {
                j++;
            }
            while (k < n && nums[k] - nums[j] < diff) {
                k++;
            }
            if (j < n && k < n && nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
                count++;
            }
            i++;
        }
        return count;
    }
};