class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ops=0;
        int min_el=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            ops+=(nums[i]-min_el);
        }
        return ops;
    }
};