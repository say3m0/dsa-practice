vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0,res,nums);
        return res ;
    }

    void backtrack(int idx, vector<vector<int>>&res,vector<int>&nums){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
        swap(nums[i],nums[idx]);
        backtrack(idx+1,res,nums);
        swap(nums[i],nums[idx]);
        }
    }