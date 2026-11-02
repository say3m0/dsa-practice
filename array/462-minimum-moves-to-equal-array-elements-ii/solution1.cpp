class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid=nums.size()/2-1;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(abs(nums[mid]-nums[i]));
        }
        return ans;
    }
    
};
//O(nlog(n))