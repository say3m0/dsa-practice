class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        vector<vector<int>> res;
        backtrack(0,res,nums);
        return res ;
    }
    void backtrack(int idx, vector<vector<int>>&res,vector<int>&nums){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int>s;
        for(int i=idx;i<nums.size();i++){
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
        swap(nums[i],nums[idx]);
        backtrack(idx+1,res,nums);
        swap(nums[i],nums[idx]);
        }
    }
};