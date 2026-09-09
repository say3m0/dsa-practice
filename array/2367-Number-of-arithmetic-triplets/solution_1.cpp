//Using set

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int>s(nums.begin(),nums.end());
        int counter=0;
        for(int i=0;i<s.size();i++){
            if(s.count(nums[i]+diff) && s.count(nums[i]+diff*2))counter++;
        }
        return counter;
    }
};