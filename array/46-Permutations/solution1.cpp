
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tempList;
        backtrack(res,tempList,nums);
        return res;
    }

   void backtrack(vector<vector<int>>&res,vector<int>&tempList,vector<int>&nums){
        if(tempList.size()==nums.size()){
            res.push_back(tempList);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(tempList.begin(),tempList.end(),nums[i])!=tempList.end()) continue;
                tempList.push_back(nums[i]);
                backtrack(res,tempList,nums);
                tempList.pop_back();
        }
    }
};