class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int count = 0;
        int left = 0;
        
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && nums[i] == nums[j]) {//getting frequency by looping
                j++;
            }
            int freq = j - i;
            int right = n - j; 
            count += left * freq * right;
            left += freq;
            i = j;
        }
        return count;
    }
};