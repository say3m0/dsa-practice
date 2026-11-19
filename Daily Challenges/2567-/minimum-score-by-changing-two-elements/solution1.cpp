class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size()-1,cntF=0,cntL=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[0]==nums[i])cntF++;
            if(nums[n]==nums[i])cntL++;
        }
        if(cntF<2 && cntL<2){return min({nums[n]-nums[2],nums[n-2]-nums[0],nums[n-1]-nums[1]});}
        else if(cntF>=2 && cntL<2)return nums[n-2]-nums[0];
        else if(cntF<2 && cntL>=2)return nums[n]-nums[2];
        return nums[n]-nums[0];
    }
};