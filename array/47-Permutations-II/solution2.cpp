
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tempList;
        vector<bool>visited(nums.size(),false);
        backtrack(res,tempList,nums,visited);
        return res;
    }

   void backtrack(vector<vector<int>>&res,vector<int>&tempList,vector<int>&nums,vector<bool>&visited){

        if(tempList.size()==nums.size()){
            res.push_back(tempList);
            return;
        }
        unordered_set<int>usedInThisLevel;

        
        for(int i=0;i<nums.size();i++){
                if(usedInThisLevel.count(nums[i])) continue;
                if(visited[i]) continue;

                visited[i]=true;
                tempList.push_back(nums[i]);
                usedInThisLevel.insert(nums[i]);

                backtrack(res,tempList,nums,visited);

                tempList.pop_back();
                visited[i]=false;
        }
    }
};