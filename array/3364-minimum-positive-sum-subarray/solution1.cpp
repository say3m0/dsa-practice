class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int result=1e9;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i+k;j<nums.size() && (j-i+1)<=r;j++){
                sum+=nums[j];
                if((j-i+1)>=l && sum>0){
                    result=min(result,sum);
                }
            }
        }
        if(result==1e9) return -1;
        return result;
    }
};