class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        for(int i=0;i<nums.size();i++)nums[i]=abs(nums[i]);

        sort(nums.begin(),nums.end());

        long long ans=0;
        int i,j;
        for(i=0,j=nums.size()-1;i<j;i++,j--){
            ans+=(nums[j]*nums[j]-nums[i]*nums[i]);
        }
        if(j==i)ans+=(nums[j]*nums[j]);

        return ans;

    }
};